add_executable(server_exec main.cpp command/InfoCommand.cpp command/InfoCommand.h command/ServerCommandRepository.cpp command/ServerCommandRepository.h command/DirCommand.cpp command/DirCommand.h command/GetCommand.cpp command/GetCommand.h command/PutCommand.cpp command/PutCommand.h command/RenCommand.cpp command/RenCommand.h command/DelCommand.cpp command/DelCommand.h command/MkdirCommand.cpp command/MkdirCommand.h command/QuitCommand.cpp command/QuitCommand.h)

find_package(Threads REQUIRED)
target_link_libraries(server_exec PRIVATE base_lib ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(server_exec PRIVATE src)