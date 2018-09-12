#include <stdlib.h>
#include <string.h>
//#include "process.h"
#include "node.h"
#include <stdio.h>

struct node* init(char *u,char j, int a,int d){
	 struct node *n = (struct node *) malloc(sizeof(struct node));
	 n->user = strdup(u);
	 n->job = j;
	 n->arr=a;
	 n->dur=d;
	 n->next=NULL;
	 //printf("Ini list\n");
	 return n;
}
//inserts node at end of list
struct node* insert(struct node *head, struct node *nnode){
	struct node *cur = head;
	struct node *prev = cur;
	while(cur != NULL){
		prev =  cur;
		cur = cur->next;
	}
	prev->next = nnode;
	return head;
	
}

 int pop(struct node **head, char job){
	struct node *cur = *head;
	struct node *prev = cur;
	if(cur!= NULL && cur->job == job){
		struct node *tmp =cur;
		cur=cur->next;
		*head = cur;
		free(tmp);

		return 1;
	}

	while(cur!=NULL && cur->job !=job){
		prev = cur;
		cur = cur->next;
	}

	if(cur == NULL){
		return 0;
	}

	prev->next = cur->next;
	free(cur);
	return 1;
}

struct node sort(struct node *head){

}

void delete_list(struct node *head){
	struct node* temp;
	while(head!=NULL){
		temp =head;
		head = head->next;
		free(temp);
	}
	free(head);
}

void print_list(struct node *head){
	struct node *cur = head;
	while(cur!=NULL){
		printf("%s %c %d %d \n",cur->user,cur->job,cur->arr,cur->dur);
		cur=cur->next;
	}
	//printf("Done priniting\n");
}
