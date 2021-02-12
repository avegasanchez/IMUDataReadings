if(NOT DEFINED CMAKE_MINIMUM_REQUIRED_VERSION)
    cmake_minimum_required(VERSION 3.12)
    project(TestingData)
    find_package(YARP REQUIRED COMPONENTS os)
endif()

add_executable(${PROJECT_NAME} "main.cpp")
target_sources(TestingData PRIVATE main.cpp)
target_link_libraries(TestingData PRIVATE YARP::YARP_os
                                          YARP::YARP_init)
