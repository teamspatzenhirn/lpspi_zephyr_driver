# Example for NXP LPSPI Zephyr Driver Module
## Prerequisites
This example is build for Teensy 4.1. It is expected that this module is cloned in a directory called `lpspi` inside a `modules` directory. This can happen either manually, via git submodules or using west. Moreover, zephyr (tested with v4.3.0) must be installed and CMake must be able to find it.

## Usage
- build using `west build` or `west build --pristine` (clean build)
- flash using `west flash`

## Output
The output of the example is made available via USB registered as a CDC-ACM device: In order to show the output you can simply use: `cat /dev/ttyACM0`