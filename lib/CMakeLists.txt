# Create an interface library for dependencies
add_library(lib INTERFACE)

# Add the lib directory as an include path
target_include_directories(lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})