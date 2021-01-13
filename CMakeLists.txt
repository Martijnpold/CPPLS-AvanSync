project(CPPLS_AvanSync)
cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

set(ASIO_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/asio-1.18.0")
find_package(ASIO REQUIRED)
include_directories(${ASIO_INCLUDE_DIR})
add_compile_definitions(ASIO_STANDALONE=YES)

add_subdirectory(base)
add_subdirectory(client)
add_subdirectory(server)