cmake_minimum_required(VERSION 3.23)
project(queue)

set(CMAKE_CXX_STANDARD 20)

add_executable(queue main.cpp Queue.cpp Queue.h Shared_ptr.cpp Shared_ptr.h Iterator.cpp Iterator.h)
