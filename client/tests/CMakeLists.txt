add_executable(client_tests main.cpp)

Include(FetchContent)
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.2.2)
FetchContent_MakeAvailable(Catch2)

target_link_libraries(client_tests
        PUBLIC client_lib
        Catch2::Catch)

include(CTest)
include(Catch)
catch_discover_tests(client_tests)