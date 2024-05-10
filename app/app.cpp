#include <iostream>
#include <format>

#include "boost/property_tree/ptree.hpp"
#include "boost/property_tree/json_parser.hpp"

#include "utils.h"
#include "platform.h"

using namespace std;
namespace pt = boost::property_tree;

cst::p_ current_platform;

struct System {
    string name;
    string version;
    string platform;
};

int main() {
#ifdef _WIN32
    current_platform = cst::WINDOWS;
#elif __linux__
    current_platform = cst::LINUX;
#else
    current_platform = cst::UNKNOWN;
#endif
    System current_system;
    current_system.name = core::get_hostname();
    current_system.version = "1.0.0";
    current_system.platform = utl::platform_to_string(current_platform);

    pt::ptree root, system;

    system.put("name", current_system.name);
    system.put("version", current_system.version);
    system.put("platform", current_system.platform);

    root.add_child("system", system);
    pt::write_json("system.json", root);

    std::cout << std::format("Hello, World!\nYou are on {}\n",
            current_system.platform) << std::endl;
    return 0;
}
