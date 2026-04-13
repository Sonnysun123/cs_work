cmake_minimum_required(VERSION 3.16)
project(SFMLTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

# file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)


file(GLOB SRC_FILES CONFIGURE_DEPENDS src/TextureStore.cpp src/main.cpp)

add_executable(SFMLTest ${SRC_FILES})
target_link_libraries(SFMLTest PRIVATE sfml-graphics sfml-window sfml-system)
