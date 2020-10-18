cmake_minimum_required(VERSION 3.13)
project(WindowsCrashSendingService)

set(CMAKE_CXX_STANDARD 17)

add_executable(WindowsCrashSendingService main.cpp serviceMain.h)