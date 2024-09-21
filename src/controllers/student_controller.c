#include "controllers/student_controller.h"
#include "views/student_view.h"

void handleStudentMenuController(Student *currentStudent, Grade *gradesHead) {
    displayStudentHomepage(currentStudent, gradesHead);
}
