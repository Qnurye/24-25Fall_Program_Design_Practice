cmake_minimum_required(VERSION 3.10)
project(Var4 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(Var4 src/main.c
        src/controllers/auth_controller.c
        src/controllers/grade_controller.c
        src/controllers/teacher_controller.c
        src/controllers/student_controller.c
        src/controllers/notification_controller.c
        src/models/administrator.c
        src/models/grade.c
        src/models/student.c
        src/models/teacher.c
        src/models/notification.c
        src/views/administrator_view.c
        src/views/login_view.c
        src/views/student_view.c
        src/views/teacher_view.c
        src/utils/seed.c
        src/utils/display.c
        src/models/classroom.c
        src/models/course_schedule.c
        src/models/course_schedule_selection.c)

target_include_directories(Var4 PRIVATE include)

if (CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(Var4 PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_C_COMPILER_ID MATCHES "MSVC")
    target_compile_options(Var4 PRIVATE /W4)
endif ()
