#pragma once

#include <cstddef>
#include <cstdint>
#include <immintrin.h>
#include <random>
#include <malloc.h>
#include <string>
#include <iostream>
#include <chrono>
#include <type_traits>

// Class template for aligned array allocation
namespace AlignedMem
{
    template <typename T>
    bool IsAligned(const T* ptr, size_t alignment) {
        return reinterpret_cast<uintptr_t>(ptr) % alignment == 0;
    }

    template <typename T>
    class AlignedArray {
    public:
    
        AlignedArray(size_t size, size_t alignment) {
            data = static_cast<T*>(_aligned_malloc(size * sizeof(T), alignment));
        }
        ~AlignedArray() {
            _aligned_free(data);
        }
        T* Data() const {
            return data;
        }

    private:
        T* data;
    };
}

namespace MT {
    template <typename T>
    void FillArray(uint8_t* array, size_t size, T minValue, T maxValue, unsigned int seed) {
        std::mt19937 rng(seed);

        // Use conditional to select the distribution based on the type
        if constexpr (std::is_integral_v<T>) {
            std::uniform_int_distribution<T> distribution(minValue, maxValue);
            for (size_t i = 0; i < size; ++i) {
                array[i] = distribution(rng);
            }
        }
        else if constexpr (std::is_floating_point_v<T>) {
            std::uniform_real_distribution<T> distribution(minValue, maxValue);
            for (size_t i = 0; i < size; ++i) {
                array[i] = distribution(rng);
            }
        }
        else {
            static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>,
                "FillArray supports only integral and floating-point types");
        }
    }
}


bool Scalarscaling(uint8_t* output, const uint8_t* input, size_t inputWidth, size_t inputHeight);
bool SIMDscaling(uint8_t* output, const uint8_t* input, size_t inputWidth, size_t inputHeight);
void InitArray(uint8_t* x, size_t n, unsigned int seed);
bool CheckArgs(const uint8_t* x, size_t n);
void PrintImage(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& title);

const size_t c_NumElements = 1000000;
const size_t c_Alignment = 16;
const unsigned int c_RngSeedVal = 29;
extern "C" size_t g_NumElementsMax;
