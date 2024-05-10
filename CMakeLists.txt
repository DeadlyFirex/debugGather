cmake_minimum_required(VERSION 3.28.1)
include(cmake/build.cmake)
include(cmake/utilities.cmake)
project(debugGather
        VERSION 1.0
        DESCRIPTION "An C++23 cross-platform application to gather debug information about a platform"
        LANGUAGES C CXX)

detectOS()
detectArch()

message(STATUS "Compiling for ${PLATFORM} on ${ARCHITECTURE}")

set(CMAKE_CXX_STANDARD 23)
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

include(FetchContent)

# Include Boost
message(STATUS "Downloading Boost using FetchContent")
FetchContent_Declare(
        Boost
        URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
        URL_HASH MD5=893b5203b862eb9bbd08553e24ff146a
        DOWNLOAD_EXTRACT_TIMESTAMP ON
        EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(Boost)
message(STATUS "Finished downloading Boost")

add_custom_target(db_target ALL)
add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(utils)
