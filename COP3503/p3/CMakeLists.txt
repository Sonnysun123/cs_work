cmake_minimum_required(VERSION 3.16)
project(SFMLTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

add_executable(SFMLTest src/main.cpp)
target_link_libraries(SFMLTest PRIVATE sfml-graphics sfml-window sfml-system)