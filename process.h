//process.h

#ifndef process_h
#define process_h


struct Proc{
  char job;
  int dur;
  int arrive;
  char *user;
};
//return new Proc, null otherwise
struct Proc* PROC_init(char j, int d, int a,char *u);
void PROC_destroy(struct Proc *P );
// returns 1 if it has arrived 0 if not
int PROC_arrived( struct Proc *P, int time);
//Returns 1 if work is done, 0 if it's done
int PROC_work( struct Proc *P);
void print_PROC(struct Proc *P);
#endif
