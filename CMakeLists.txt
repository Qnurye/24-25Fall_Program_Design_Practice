cmake_minimum_required(VERSION 3.10)
project(Var4 VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)


find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
pkg_check_modules(MARIADB REQUIRED mariadb)

include_directories(${GTK4_INCLUDE_DIRS} ${MARIADB_INCLUDE_DIRS} include)
link_directories(${GTK4_LIBRARY_DIRS} ${MARIADB_LIBRARY_DIRS})

add_executable(Var4 src/main.c
        src/models/teacher.h
        src/models/student.h
        src/models/course.h
        src/models/classroom.h
        src/models/course_schedule.h
        src/models/grade.h
        src/models/student.c
        src/database/database.c
        src/database/database.h
        src/models/user.h
        src/controllers/auth_controller.c
        src/models/user.c
        src/views/login_view.c
        src/controllers/classroom_controller.h
        src/controllers/course_selection_controller.h
        src/controllers/grade_controller.h
        src/controllers/import_controller.h
        src/controllers/notification_controller.h
        src/controllers/schedule_controller.h
        src/models/notification.h)

target_link_libraries(Var4 PRIVATE ${GTK4_LIBRARIES} ${MARIADB_LIBRARIES})
target_include_directories(Var4 PRIVATE ${GTK4_INCLUDE_DIRS})
target_compile_options(Var4 PRIVATE ${GTK4_CFLAGS})

if (CMAKE_C_COMPILER_ID MATCHES "Clang|AppleClang|GNU")
    target_compile_options(Var4 PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_C_COMPILER_ID MATCHES "MSVC")
    target_compile_options(Var4 PRIVATE /W4)
endif ()
