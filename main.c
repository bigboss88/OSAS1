#include "process.h"
#include "node.h"
#include <stdio.h>
//Test
int main(){
	char dump[100];
	int time = 0;
	int i =0;
	for(i;i<4;i++){
		scanf("%s",dump);
	}
	//free(dump);
	char user[50];
	char job;
	int arrive;
	int dur;
	while(scanf("%s %c %d %d",user,&job,&arrive,&dur)>3){
		struct Proc *test = PROC_init(user,job,arrive,dur);
		print_PROC(test);
		PROC_destroy(test);
	}
}
