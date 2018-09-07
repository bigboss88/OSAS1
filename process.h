//process.h

#ifndef process_h
#define process_h

#include <stdio.h>

typedef struct {
  char job;
  int dur;
  int arrive;

} Proc;

//returns 1 if successful
int PROC_init(char j, int d, int a);
void PROC_destroy();
// returns 1 if it has arrived 0 if not
int PROC_arrived(int time);
#endif
