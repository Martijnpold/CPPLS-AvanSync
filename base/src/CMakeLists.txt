add_library(base_lib STATIC connection/Connection.cpp connection/Connection.h buffer/IO.h connection/IConnection.h buffer/StreamIO.cpp buffer/StreamIO.h command/ICommand.h buffer/SystemIO.cpp buffer/SystemIO.h command/CommandRepository.cpp command/CommandRepository.h buffer/Line.cpp buffer/Line.h buffer/IO.cpp util/ErrorUtil.cpp util/ErrorUtil.h buffer/ListIO.cpp buffer/ListIO.h util/FileUtil.cpp util/FileUtil.h)
target_include_directories(base_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Threads REQUIRED)
target_link_libraries(base_lib PRIVATE ${CMAKE_THREAD_LIBS_INIT})