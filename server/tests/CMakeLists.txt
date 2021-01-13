add_executable(server_tests main.cpp command/DelCommandTest.cpp command/DirCommandTest.cpp command/GetCommandTest.cpp util/TestFileUtil.h util/TestIO.h command/InfoCommandTest.cpp command/MkdirCommandTest.cpp command/PutCommandTest.cpp command/QuitCommandTest.cpp command/RenCommandTest.cpp)

Include(FetchContent)
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.2.2)
FetchContent_MakeAvailable(Catch2)

target_link_libraries(server_tests
        PUBLIC server_lib
        Catch2::Catch)

include(CTest)
include(Catch)
catch_discover_tests(server_tests)