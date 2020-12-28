add_executable(server_exec main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(server_exec PRIVATE base_lib ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(server_exec PRIVATE src)