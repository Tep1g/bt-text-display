# Define the build directory
BUILD_DIR = build

# Define the CMake and Make commands based on the environment
ifeq ($(OS), Windows_NT)
    CMAKE_COMMAND = cmake -G "MinGW Makefiles" -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
 	MAKE_COMMAND = mingw32-make
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S), Linux)
		CMAKE_COMMAND = cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 ..
		MAKE_COMMAND = make
    else
        $(error Unsupported OS: $(UNAME_S))
    endif
endif

# Default target to run CMake and generate build files
all:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && $(CMAKE_COMMAND)
	cd $(BUILD_DIR) && $(MAKE_COMMAND)

clean:
	rm -rf $(BUILD_DIR)
