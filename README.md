# bt-text-display

### Setup and Instructions

#### Windows
* Install Git (includes Bash terminal): https://git-scm.com/downloads
* Install CMake: https://cmake.org/download/
* Install the Arm GNU Toolchain: https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain
* Install Make and MinGW using Chocolatey
  * Chocolatey should already be installed from the Git install, otherwise install it: https://chocolatey.org/
  * Run these commands from an Administrator Command Prompt:
  
    `> choco install make`
    
    `> choco install mingw`

#### Linux
All the tools we need, including Git and Make, should be available after installing these packages:

`$ sudo apt install cmake`

`$ sudo apt install gcc-arm-none-eabi`

`$ sudo apt install build-essential`

### Before Building the Project for the first time

`$ git submodule init`

`$ git submodule update`

### Building the Project

Build the project with `$ make`

Delete the current build with `$ make clean`