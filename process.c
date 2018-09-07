//process.c

#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include "process.h"


struct Proc* PROC_init(char j, int d, int a,char *u){
  struct Proc *P;
  P = malloc(sizeof(struct Proc*));
  if(P == NULL) return P; //failed
  P->job = j;
  P->dur = d;
  P->arrive =a;
  P->user = strdup(u);
  return P;
}

void PROC_destroy(struct Proc *P){
  free(P);
}

int PROC_arrived(struct Proc *P,int time){
   if(P->arrive <= time){
   	return 1;
   }
   return 0;
}
int PROC_work(struct Proc *P){
	if(P->dur == 0){return 0;}
	P->dur= P->dur-1;
	return 1;
}

void print_PROC(struct Proc *P){
	printf("\n%s	%c 	%d 	%d \n", P->user,P->job,P->dur,P->arrive);
}