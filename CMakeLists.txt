CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main
    main.cpp
)

ADD_EXECUTABLE(test1
    unit_tests/connector_tests.cpp
)

TARGET_LINK_LIBRARIES(test1 gtest)
TARGET_COMPILE_DEFINITIONS(test1 PRIVATE gtest_disable_pthreads=ON)