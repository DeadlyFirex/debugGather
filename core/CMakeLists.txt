cmake_minimum_required(VERSION 3.28.1)
project(core)

# Add the library
add_library(core STATIC)

# Specify the source files
target_sources(core PRIVATE
        include/constants.h constants.cpp
        include/platform.h linux/platform.cpp windows/platform.cpp
)

# Specify the required C++ standard
target_compile_features(core PRIVATE cxx_std_23)

# Link targets if Windows
if (${PLATFORM} STREQUAL "windows")
    message(STATUS "Linking Windows libraries")
    target_link_libraries(core PRIVATE ws2_32)
    target_link_libraries(core PRIVATE wsock32)
endif()

# Include directories
target_include_directories(core PUBLIC include)
