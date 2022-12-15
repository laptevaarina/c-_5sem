cmake_minimum_required(VERSION 3.17)
project(task_2)

set (BOOST_ROOT "C:/local/boost_1_81_0")

set (CMAKE_CXX_STANDARD 20)
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
add_executable(task_2 main.cpp)
target_link_libraries(task_2 ${Boost_SYSTEM_LIBRARY} ws2_32)


