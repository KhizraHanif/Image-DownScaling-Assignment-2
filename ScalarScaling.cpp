#include "ImageScaling.h"
#include <iostream>
size_t g_NumElementsMax = c_NumElements;
bool CheckArgs(const uint8_t* x, size_t n) {
    if (n == 0 || n > g_NumElementsMax)
        return false;
    if ((n % 64) != 0)
        return false;
    if (!AlignedMem::IsAligned(x, c_Alignment))
        return false;

    return true;
}


void InitArray(uint8_t* x, size_t n, unsigned int rng_seed) {
    int rng_min_val = 0;
    int rng_max_val = 255;
    MT::FillArray(reinterpret_cast<uint8_t*>(x), n, rng_min_val, rng_max_val, rng_seed);
}

bool Scalarscaling(uint8_t* output, const uint8_t* input, size_t inputWidth, size_t inputHeight) {
    if (!CheckArgs(input, inputWidth * inputHeight))
        return false;

    size_t outputWidth = inputWidth / 4;
    size_t outputHeight = inputHeight / 4;

    for (size_t i = 0; i < inputHeight; i += 4) {
        for (size_t j = 0; j < inputWidth; j += 4) {
            int sum = 0;

            // Loop through the 4x4 block
            for (size_t x = 0; x < 4; ++x) {
                for (size_t y = 0; y < 4; ++y) {
                    sum += input[(i + x) * inputWidth + (j + y)];
                }
            }

            int mean = sum / 16;

            output[(i / 4) * outputWidth + (j / 4)] = static_cast<uint8_t>(mean);
        }
    }

    return true;
}


void PrintImage(const std::vector<uint8_t>& image, size_t width, size_t height, const std::string& title) {
    std::cout << title << ":\n";
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            std::cout << static_cast<int>(image[i * width + j]) << " ";
        }
        std::cout << std::endl;
    }
}

