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
