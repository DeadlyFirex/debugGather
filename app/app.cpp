#include <iostream>
#include "boost/json/src.hpp"

#include "utils.h"


cst::p_ current_platform;

int main() {
#ifdef _WIN32
    current_platform = cst::WINDOWS;
#elif __linux__
    current_platform = cst::LINUX;
#else
    current_platform = cst::UNKNOWN;
#endif
    std::cout << std::format("Hello, World!\nYou are on {}\n",
            utl::platform_to_string(current_platform)) << std::endl;

    return 0;
}
