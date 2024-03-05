cmake_minimum_required(VERSION 3.16.3)
project(mearlymath)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Add Google Test
add_subdirectory(googletest)

# Build the non-test code as a library
add_library(mearlymath INTERFACE)
target_include_directories(mearlymath INTERFACE  ${CMAKE_CURRENT_SOURCE_DIR})

# Add your source files and set up your project
add_executable(adderTest adder.cpp GmockTest.cpp)
set_target_properties(adderTest PROPERTIES PUBLIC_HEADER adder.hpp)
install(TARGETS adderTest DESTINATION lib)

# Link with Google Test libraries
target_link_libraries(adderTest gtest gtest_main)

# Add the test
add_test(
    NAME adderTest
    COMMAND adderTest
)

include_directories(${GMOCK_INCLUDE_DIRS})

if(NOT CMAKE_CXX_FLAGS)
    set(CMAKE_CXX_FLAGS "-D_GLIBCXX_ASSERTIONS -pedantic -Wall -Werror -Wextra \
        -fwrapv -Wformat=2 -Wmissing-include-dirs -Wunused-parameter -Wuninitialized -Walloca \
        -Wfloat-equal -Wshadow -Wcast-qual -Wsign-conversion -Wformat-security -Wcast-align \
        -Wredundant-decls -Weffc++ -std=c++2a")

    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 8.0)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
            -Wformat-signedness -Wimplicit-fallthrough=5 -Wduplicated-branches -Wduplicated-cond \
            -Wlogical-op -Walloc-zero")

    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
            -Wno-error=unknown-warning-option -Wno-error=format-nonliteral")

    else()
        message(FATAL_ERROR "We do not support your compiler \"${CMAKE_CXX_COMPILER_ID}\", version ${CMAKE_CXX_COMPILER_VERSION}")
    endif()

    if (KMODS_UT_WITHOUT_DT_FOR_SUT_BUILD)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DKMODS_UT_WITHOUT_DT_FOR_SUT_BUILD")
    endif()

    if(DEBUG_PRINT_ENABLED)
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG_PRINT_ENABLED")
    endif()
endif(NOT CMAKE_CXX_FLAGS)