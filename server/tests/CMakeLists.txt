add_executable(server_tests main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

Include(FetchContent)
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.2.2)
FetchContent_MakeAvailable(Catch2)

target_link_libraries(server_tests
        PUBLIC base
        Catch2::Catch)

include(CTest)
include(Catch)
catch_discover_tests(server_tests)