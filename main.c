//#include "process.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
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
	i = 0;
	struct node *in;
	struct node *test;
	int min =0;
	while(scanf("%s %c %d %d",user,&job,&arrive,&dur)>3){
		if(i==0){
			in = init(user,job,arrive,dur);
			min=arrive;
		}
		else{
			test = init(user,job,arrive,dur);
			 in = insert(in,test);
			 if(arrive < min){
			 	min = arrive;
			 }
		}
		i++;
	}
	print_list(in);
	printf("%s\n",in->next->user );
	printf("time 	Job\n");
	time = min;
	while(in != NULL){ // while there are still jobs
		//print_list(in);
		struct node *cur = (struct node *) malloc(sizeof(struct node));
		cur = in;
		struct node *work = (struct node *) malloc(sizeof(struct node*)); // this is one that should be worked on
		work = cur;
		//printf("Going into while loop\n");
		while (cur != NULL){ // go through list
			//printf("%d\n",cur->dur );
			//printf("LOOP\n");
			if(work ==NULL ){work = cur;}

			//printf("lol\n");
			//printf("%c %c \n",cur->job);
			if(cur->dur < work->dur && cur->arr <= time){ // The one that should be worked on
				//has arrived and is smallest dur
				//printf("made %c work\n",cur->job);
				work = cur;
			}
			if(cur->dur == 1){ // if this job is done remove it for some reason it will work on 0 so I set to 1
				struct node *tmp = (struct node *) malloc(sizeof(struct node));
				tmp =cur;
				cur = cur->next;
				//printf("POP %c \n",tmp->job);
				pop(&in,tmp->job);
				//print_list(in);
				//printf("Done POPing you\n");
			}

			if(cur == NULL){break;}
			cur = cur->next;
		}


		if(work!=NULL && work->dur>0){ // if you found a job
			work->dur = work->dur -1;
			printf("%d 	%c\n",time,work->job);
		}
		time++;
	}
	printf("%d 	IDLE\n", time++);





	//free(cur);
	//free(work);
	// /free(tmp);
	delete_list(in);
}
