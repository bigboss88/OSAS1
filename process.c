//process.c

#include <stdlib.h>
#include "process.h"
Proc *P;
int PROC_init(char j, int d, int a){
  P = malloc(sizeof(Proc));
  if(P == null) return 0; //failed
  P->job = j;
  P->dur = d;
  P->arrive =a;
  return 1;
}

PROC_destroy(){
  free(P);
}

int PROC_arrived(int time){
  return (P->arrive <= time);
}
