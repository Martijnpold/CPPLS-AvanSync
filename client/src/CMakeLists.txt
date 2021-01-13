file(GLOB_RECURSE CLIENT_SOURCES "*.cpp")
list(REMOVE_ITEM CLIENT_SOURCES "main.cpp")

add_library(client_lib STATIC ${CLIENT_SOURCES})
target_include_directories(client_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(client_lib PUBLIC base_lib)

add_executable(client_exec main.cpp)

target_link_libraries(client_exec
        PUBLIC client_lib
        Catch2::Catch)