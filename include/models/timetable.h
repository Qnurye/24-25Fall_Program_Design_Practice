#ifndef TIMETABLE_H
#define TIMETABLE_H

#define MAX_PERIODS 13

typedef struct {
    char start_time[6];  // Format: "HH:MM"
    char end_time[6];    // Format: "HH:MM"
} TimePeriod;

static const TimePeriod TIMETABLE[MAX_PERIODS] = {
    {"08:00", "08:45"},
    {"08:50", "09:35"},
    {"09:50", "10:35"},
    {"10:45", "11:30"},
    {"11:35", "12:20"},
    {"13:00", "13:45"},
    {"13:50", "14:35"},
    {"14:45", "15:30"},
    {"15:40", "16:25"},
    {"16:30", "17:15"},
    {"18:00", "18:45"},
    {"18:50", "19:35"},
    {"19:40", "20:25"}
};

#endif // TIMETABLE_H
