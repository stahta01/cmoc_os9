/*
 * time.h - Time definitions
 */

#include <os.h>

/* OS-9 time packet structure */
typedef struct os_time
{
    byte year;
    byte month;
    byte day;
    byte hours;
    byte minutes;
    byte seconds;
} _os_time;

error_code _os_getime(_os_time *time);
error_code _os_setime(_os_time *time);
