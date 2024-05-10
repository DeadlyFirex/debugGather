#pragma once
#include <string>
#ifdef __linux__
#include <unistd.h>
#include <cstring>
#elif _WIN32
#include <winsock2.h>
#endif
namespace core {
    std::string get_hostname();
}
