add_executable(client_exec main.cpp)

target_link_libraries(client_exec PRIVATE base_lib)
target_include_directories(client_exec PRIVATE src)