add_executable(server_exec main.cpp)

target_link_libraries(server_exec PRIVATE base_lib)
target_include_directories(server_exec PRIVATE src)