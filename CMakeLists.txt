cmake_minimum_required(VERSION 3.10)
project(Var4 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(Var4 src/main.c
        src/administrator.c
        include/administrator.h
        include/data.h
        include/entities.h
        include/login.h
        include/student.h
        include/teacher.h
        src/data.c
        src/login.c
        src/student.c
        src/teacher.c)

target_link_libraries(Var4 PRIVATE)
target_include_directories(Var4 PRIVATE)
target_compile_options(Var4 PRIVATE)

if (CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(Var4 PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_C_COMPILER_ID MATCHES "MSVC")
    target_compile_options(Var4 PRIVATE /W4)
endif ()
