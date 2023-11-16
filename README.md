# Image-DownScaling-Assignment-2
SIMD and Scalar approach to down scale the image using C++
## Description

This project implements image scaling algorithms in C++. It includes both scalar and SIMD (Single Instruction, Multiple Data) solutions for scaling down an image by 16x. The goal is to leverage SIMD instructions to achieve improved performance.

## Table of Contents

- [Description](#description)
- [Table of Contents](#table-of-contents)
- [Build Instructions](#build-instructions)
- [Usage](#usage)
- [License](#license)

## Build Instructions

To build the project, follow these instructions:

1. Clone the repository:

    ```bash
    git clone https://github.com/your-username/image-scaling-project.git
    ```

2. Navigate to the project directory:

    ```bash
    cd image-scaling-project
    ```

3. Build the project:

    ```bash
    make
    ```

    If using Visual Studio, open the solution file and build using the IDE.

## Usage

After building the project, you can run the executable to test the image-scaling algorithms. The following functions are available:

- `Scalarscaling`: Scales down an image using a scalar (non-SIMD) approach.
- `SIMDscaling`: Scales down an image using SIMD instructions.

# Setting Up Visual Studio for SIMD Programming

To enable SIMD (Single Instruction, Multiple Data) instructions in Visual Studio for this project, follow these steps:                                                   # Steps

1. **Configure Project Properties:
   - Right-click on the project in the Solution Explorer.
   - Select "Properties."

2. **Set Configuration to Release:**
   - In the Configuration dropdown, select "Release" (for optimized builds).

3. **Choose Target Architecture:**
   - Under "Configuration Properties," go to "C/C++" -> "Code Generation."
   - Set "Enable Enhanced Instruction Set" to the desired SIMD instruction set (e.g., AVX2 or SSE2). I have used AVX2. 

4. **Enable Optimization:**
   - In the same "Code Generation" settings, set "Optimization" to the desired level (e.g., "Maximize Speed (/O2)").

5. **Enable Intrinsic Functions:**
   - Under "C/C++" -> "Language," enable "Enable Enhanced Instruction Set" for intrinsics.


7. **Build and Run:**
   - Build project.
   - Run the executable to verify SIMD instructions are being used.

