file(GLOB_RECURSE SERVER_SOURCES "*.cpp")
list(REMOVE_ITEM SERVER_SOURCES "main.cpp")

add_library(server_lib STATIC ${SERVER_SOURCES})
target_include_directories(server_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(server_lib PUBLIC base_lib)

add_executable(server_exec main.cpp)

target_link_libraries(server_exec
        PUBLIC server_lib
        Catch2::Catch)