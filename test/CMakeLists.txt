cmake_minimum_required(VERSION 3.31)
project(esamelabanas)

add_subdirectory(lib/googletest googletest-build)
include_directories(../lib/googletest/googletest/include)

set(SOURCE_TEST_FILES runTests.cpp ../ContoCorrente.h ../ContoCorrente.cpp ../Transazione.h ../Transazione.cpp
        ContoCorrenteTest.cpp
        TransazioneTest.cpp)

add_executable(runTests ${SOURCE_TEST_FILES} ContoCorrenteTest.cpp TransazioneTest.cpp)

target_link_libraries(runTests gtest gtest_main)
