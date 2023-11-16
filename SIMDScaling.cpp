#include <immintrin.h>
#include <cstdint>
#include <cstddef>
#include "ImageScaling.h"

bool SIMDscaling(uint8_t* output, const uint8_t* input, size_t inputWidth, size_t inputHeight) {
    if (!CheckArgs(input, inputWidth * inputHeight))
        return false;

    size_t outputWidth = inputWidth / 4;
    size_t outputHeight = inputHeight / 4;

    for (size_t i = 0; i < inputHeight; i += 4) {
        for (size_t j = 0; j < inputWidth; j += 4) {
            __m256i sum = _mm256_setzero_si256();

            // Loop through the 4x4 block using AVX2
            for (size_t x = 0; x < 4; ++x) {
                for (size_t y = 0; y < 4; ++y) {
                    size_t idx = (i + x) * inputWidth + (j + y);
                    __m256i inputValues = _mm256_cvtepu8_epi16(_mm_loadu_si128(reinterpret_cast<const __m128i*>(&input[idx])));
                    sum = _mm256_add_epi16(sum, inputValues);
                }
            }

            // Calculate the mean using AVX2
            __m256i mean = _mm256_srai_epi16(sum, 4);
            mean = _mm256_packus_epi16(mean, mean);
            mean = _mm256_permute4x64_epi64(mean, 0xD8);  // Permute to get the correct order
            __m128i mean128 = _mm256_castsi256_si128(mean);  // Extract the lower 128 bits

            // Store the result back to the output array
            _mm_storeu_si128(reinterpret_cast<__m128i*>(&output[(i / 4) * outputWidth + (j / 4)]), mean128);
        }
    }

    return true;
}
