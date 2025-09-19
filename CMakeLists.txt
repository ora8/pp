cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(PoorProgrammerProject VERSION 1.0)

# Specify the library's source files
set(SOURCES
    src/stdvec.c
    src/stdstring.c
    src/stdstring_view.c
    src/function.c
    # Add more source files as needed
)

# Create the static library
add_library(pp STATIC ${SOURCES})

target_include_directories(pp PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# Add the demo executable
add_executable(split_demo examples/split_demo.c)

# Link the library to the demo executable
target_link_libraries(split_demo PRIVATE pp)

# Optionally, you can set the C standard
set_target_properties(pp PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)