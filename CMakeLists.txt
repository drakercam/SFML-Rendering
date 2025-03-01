cmake_minimum_required(VERSION 3.22.1)
project(rendering)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find SFML
find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics window system audio)
include_directories(${CMAKE_SOURCE_DIR}/src ${SFML_INCLUDE_DIR})

# Add all source files
set(SOURCES
    src/main.cpp
    src/events.cpp
    src/camera.cpp
)

set(HEADERS
    src/star.hpp
    src/conf.hpp
    src/events.hpp
    src/camera.hpp
)

# Create executable
add_executable(rendering ${SOURCES} ${HEADERS})

# CMakeLists.txt
add_custom_command(TARGET rendering POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/textures
    $<TARGET_FILE_DIR:rendering>/textures
)

# Link SFML libraries
target_link_libraries(rendering PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
