# Define the build directory
BUILD_DIR = build

# Define the CMake generator
CMAKE_GENERATOR = "MinGW Makefiles"

# Default target to run CMake and generate build files
all:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake -G $(CMAKE_GENERATOR) ..
	cd $(BUILD_DIR) && mingw32-make

clean:
	rm -rf $(BUILD_DIR)
