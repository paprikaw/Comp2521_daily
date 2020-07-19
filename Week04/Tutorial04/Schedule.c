// Schedule ADT implementation

#include <stdio.h>
#include <stdlib.h>

#include "Schedule.h"
#include "Time.h"
#include "Tree.h"

struct schedule {
    Tree times;
    int  count;
};

// Creates a new schedule
Schedule ScheduleNew(void) {
    Schedule s = malloc(sizeof(*s));
    if (s == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    s->times = TreeNew();
    s->count = 0;
    return s;
}

// Frees all memory associated with a given schedule
void ScheduleFree(Schedule s) {
    TreeFree(s->times);
    free(s);
}

// Gets the number of times added to the schedule
int  ScheduleCount(Schedule s) {
    return s->count;
}

// Attempts to schedule a new landing time. Returns true if the time was
// successfully added, and false otherwise.
bool ScheduleAdd(Schedule s, Time t) {
    Time ceiling = TreeCeiling(s->times, t);
    Time floor = TreeFloor(s->times, t);

    // First time insert a t into schedule
    if (ceiling == NULL && floor == NULL) {
        TreeInsert(s->times, t);
        s->count++;
        return true;
    }
    // If no ceiling time
    if (ceiling == NULL) {
        if (TimeCmp(t, TimeAddMinutes(floor, 10)) <= 0) {
        return false;
        } else {
            TreeInsert(s->times, t);
            s->count++;
            return true;
        }
    }
        
    
    // If no floor time
    if (floor == NULL) {
        if (TimeCmp(t, TimeSubtractMinutes(ceiling, 10)) >= 0) {
        return false;
        } else {
            TreeInsert(s->times, t);
            s->count++;
            return true;
        }
    }

    // If the time have ceiling time
    // and floor time and the interval of them is less than 10 minites
    if (TimeCmp(t, TimeAddMinutes(floor, 10)) <= 0 &&
    TimeCmp(t, TimeSubtractMinutes(ceiling, 10)) >= 0) {
        return false;
    }
    


    TreeInsert(s->times, t);
    s->count++;
    return true;
}

// Shows  all  the landing times in the schedule. If mode is 1, only the
// times are shown. If mode is 2, the underlying data structure is shown
// as well.
void ScheduleShow(Schedule s, int mode) {
    if (mode == 1) {
        TreeList(s->times);
    } else if (mode == 2) {
        TreeShow(s->times);
    }
}
