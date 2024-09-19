#ifndef DATA_H
#define DATA_H

#include "entities.h"

void saveStudentsToFile(Student *head, const char *filename);

void saveTeachersToFile(Teacher *head, const char *filename);

Student *loadStudentsFromFile(const char *filename);

Teacher *loadTeachersFromFile(const char *filename);

Administrator *loadAdministratorsFromFile(const char *filename);

#endif
