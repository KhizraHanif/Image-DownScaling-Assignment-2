#include "ImageScaling.h"
#include <vector>
#include <crtdbg.h>
#include <iostream>
#include <iostream>
#include <chrono>
bool CompareImages(const std::vector<uint8_t>& img1, const std::vector<uint8_t>& img2) {
    if (img1.size() != img2.size()) {
        return false;
    }

    for (size_t i = 0; i < img1.size(); ++i) {
        if (img1[i] != img2[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    const size_t inputWidth = 32;
    const size_t inputHeight = 32;
    const size_t inputSize = inputWidth * inputHeight;
    std::vector<uint8_t> input(inputSize);
    std::vector<uint8_t> scalarOutput(inputWidth / 4 * inputHeight / 4);
    std::vector<uint8_t> simdOutput(inputWidth / 4 * inputHeight / 4);
    // Initialize input array
    InitArray(input.data(), inputSize, 29);

    // Timing for Scalar Scaling
    auto startScalar = std::chrono::high_resolution_clock::now();
    Scalarscaling(scalarOutput.data(), input.data(), inputWidth, inputHeight);
    auto endScalar = std::chrono::high_resolution_clock::now();
    auto durationScalar = std::chrono::duration_cast<std::chrono::microseconds>(endScalar - startScalar).count();
    std::cout << "Scalar Scaling Execution Time: " << durationScalar << " microseconds\n";

    // Timing for SIMD Scaling
    auto startSIMD = std::chrono::high_resolution_clock::now();
    SIMDscaling(simdOutput.data(), input.data(), inputWidth, inputHeight);
    auto endSIMD = std::chrono::high_resolution_clock::now();
    auto durationSIMD = std::chrono::duration_cast<std::chrono::microseconds>(endSIMD - startSIMD).count();
    std::cout << "SIMD Scaling Execution Time: " << durationSIMD << " microseconds\n";


    // Perform the scaling down operation using scalar solution
    if (Scalarscaling(scalarOutput.data(), input.data(), inputWidth, inputHeight)) {
        std::cout << "Scalar Scaling Successful!\n";
    }
    else {
        std::cerr << "Scalar Scaling Failed!\n";
    }

    // Perform the scaling down operation using SIMD (AVX2) solution
    if (SIMDscaling(simdOutput.data(), input.data(), inputWidth, inputHeight)) {
        std::cout << "SIMD Scaling Successful!\n";
    }
    else {
        std::cout << "SIMD Scaling Failed!\n";
    }

    PrintImage(input, inputWidth, inputHeight, "Input Image");
    // Scalar scaling
    Scalarscaling(scalarOutput.data(), input.data(), inputWidth, inputHeight);
    PrintImage(scalarOutput, inputWidth / 4, inputHeight / 4, "Scaled Down Image (Scalar)");

    // SIMD scaling
    SIMDscaling(simdOutput.data(), input.data(), inputWidth, inputHeight);
    PrintImage(simdOutput, inputWidth / 4, inputHeight / 4, "Scaled Down Image (SIMD)");


    return 0;

}