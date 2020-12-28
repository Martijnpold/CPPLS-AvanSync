add_executable(server_exec main.cpp command/InfoCommand.cpp command/InfoCommand.h command/ServerCommandRepository.cpp command/ServerCommandRepository.h command/DirCommand.cpp command/DirCommand.h)

find_package(Threads REQUIRED)
target_link_libraries(server_exec PRIVATE base_lib ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(server_exec PRIVATE src)