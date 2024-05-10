#ifdef __linux__
#include "platform.h"

std::string core::get_hostname() {
    char hostname[1024];
    gethostname(hostname, 1024);
    return std::string(hostname);
}

#endif
