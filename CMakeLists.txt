cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/submodules/pico-sdk)
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Pull in FreeRTOS
set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/submodules/FreeRTOS-Kernel)
include(${FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

project(app C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

# Add the lib directory (which has its own CMakeLists.txt)
add_subdirectory(lib)

add_executable(app src/main.c)

# pull in common dependencies
target_link_libraries(app pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4 lib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(app)

# enable usb output, disable uart output
pico_enable_stdio_usb(app 1)
pico_enable_stdio_uart(app 1)