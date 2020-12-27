project(CPPLS_AvanSync)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

add_subdirectory(base)
add_subdirectory(client)
add_subdirectory(server)