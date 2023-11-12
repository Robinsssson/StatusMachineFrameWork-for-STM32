cmake_minimum_required(VERSION 3.20)
project(StatusMetine VERSION 1.1)

include_directories(include/lib include/src)


add_executable(demo test/main.c src/register.c lib/linklist.c)