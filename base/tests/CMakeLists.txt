add_executable(base_tests main.cpp buffer/LineTest.cpp buffer/ListIOTest.cpp command/CommandRepository.cpp util/TestCommand.h util/TestConnection.h)

Include(FetchContent)
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.2.2)
FetchContent_MakeAvailable(Catch2)

target_link_libraries(base_tests
        PUBLIC base_lib
        Catch2::Catch)

include(CTest)
include(Catch)
catch_discover_tests(base_tests)