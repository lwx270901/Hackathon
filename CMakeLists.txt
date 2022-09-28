cmake_minimum_required(VERSION 3.22)
project(ThreadPool)

set(CMAKE_CXX_STANDARD 14)

add_executable(ThreadPool main.cpp module/SafeQueue.cpp module/SafeQueue.h module/ThreadPool.cpp module/ThreadPool.h)
