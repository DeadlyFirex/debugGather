cmake_minimum_required(VERSION 3.28)
project(core)

# Add the library
add_library(core STATIC)

# Specify the source files
target_sources(core PRIVATE
        include/constants.h constants.cpp
)

# Specify the required C++ standard
target_compile_features(core PRIVATE cxx_std_23)

# Include directories
target_include_directories(core PUBLIC include)
