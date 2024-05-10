#include "utils.h"

std::string utl::platform_to_string(cst::p_ platform) {
    switch (platform) {
        case cst::WINDOWS:
            return "Windows";
        case cst::LINUX:
            return "Linux";
        default:
            return "Unknown";
    }
}
