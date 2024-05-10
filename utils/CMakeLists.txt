cmake_minimum_required(VERSION 3.28.1)
project(utils)

# Add the library
add_library(utils STATIC)

# Specify the source files
target_sources(utils PRIVATE
        include/utils.h utils.cpp
)

# Specify the required C++ standard
target_compile_features(utils PRIVATE cxx_std_23)

# Link the library
target_link_libraries(utils PRIVATE core)

# Include directories
target_include_directories(utils PUBLIC include)

# Add dependencies
add_dependencies(utils core)
