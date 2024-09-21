cmake_minimum_required(VERSION 3.10)
project(Var4 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(Var4 src/main.c
        src/controllers/login_controller.c
        src/controllers/grade_controller.c
        src/controllers/teacher_controller.c
        src/controllers/student_controller.c
        src/models/administrator.c
        src/models/grade.c
        src/models/student.c
        src/models/teacher.c
        src/views/administrator_view.c
        src/views/login_view.c
        src/views/student_view.c
        src/views/teacher_view.c
        src/utils/seed.c
        src/utils/display.c)

add_executable(test_runner
        tests/test_runner.c
        tests/test_student.c
        tests/test_teacher.c
        tests/test_administrator.c
        tests/test_grade.c
        src/models/student.c
        src/models/teacher.c
        src/models/administrator.c
        src/models/grade.c
        src/utils/display.c)

target_include_directories(Var4 PRIVATE include)
target_include_directories(test_runner PRIVATE include)

if (CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(Var4 PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(test_runner PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_C_COMPILER_ID MATCHES "MSVC")
    target_compile_options(Var4 PRIVATE /W4)
endif ()
