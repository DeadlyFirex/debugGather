cmake_minimum_required(VERSION 3.28)
project(app)

# Source files
add_executable(app app.cpp)

# Find dependencies
find_package(Boost 1.84.0 COMPONENTS filesystem regex)

# Link libraries
target_link_libraries(app PRIVATE core utils)
target_link_libraries(app PRIVATE Boost::filesystem Boost::regex Boost::json)

# Add definitions and properties
set_target_properties(app PROPERTIES OUTPUT_NAME ${EXECUTABLE_NAME})

# Include directories
target_include_directories(app PRIVATE include)

# Specify the required C++ standard
target_compile_features(app PRIVATE cxx_std_23)

# Add dependencies
add_dependencies(app core)
add_dependencies(app utils)
add_dependencies(db_target app)
