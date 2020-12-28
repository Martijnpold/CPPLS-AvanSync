add_executable(client_exec main.cpp command/InfoCommand.cpp command/InfoCommand.h command/ClientCommandRepository.cpp command/ClientCommandRepository.h command/DirCommand.cpp command/DirCommand.h)

find_package(Threads REQUIRED)
target_link_libraries(client_exec PRIVATE base_lib ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(client_exec PRIVATE src)