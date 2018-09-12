#include <stdlib.h>
#include <string.h>
#include "process.h"
#include "node.h"
#include <stdio.h>

struct node* init(struct Proc *P){
	 struct node *n = malloc(sizeof(struct node*));
	 n->process=P;
	 n->next=NULL;
	 printf("Ini list\n");
	 return n;
}
struct node* insert(struct node *head, struct Proc *P){
	struct node *cur = head;
	struct node *prev = NULL;
	printf("in insert\n");
	while(cur!=NULL){
		printf("In while loop\n");
		if(P->dur >= cur->process->dur){ //found location to add
			printf("breaking while loop\n");
			break;
		}
		printf("prev =cur\n");
		prev=cur;

		cur=cur->next;
		printf("1\n");
	}

	if(prev==NULL){ // at front
		struct node *nhead = init(P);
		nhead->next = cur;
		head = nhead;
		return head;
		printf("2\n");
	}
	else if(cur==NULL){ //at end
		prev->next = init(P);
		return head;
		printf("3\n");
	}

	else{ //Somewhere in middle
		struct node *nnode = init(P);
		prev->next = nnode;
		nnode->next = cur;
		return head;
		printf("4\n");
	}
}

 int pop(struct node *head, char job){
	struct node *cur = head;
	struct node *prev = NULL;

	while(cur != NULL){
		if(cur->process->job == job){ // found it
			break;
		}
		cur = prev;
		cur = cur->next;
	}

	if(prev == NULL){ // at front
		head = cur->next;
		PROC_destroy(cur->process);
		return 1;
	}

	else if(cur->next == NULL){ // at end
		prev->next =NULL;
		PROC_destroy(cur->process);
		return 1;
	}
	else if(cur->next != NULL &&prev != NULL){ //somewhere in middle
		prev->next = cur->next;
		PROC_destroy(cur->process);
		return 1;
	}
	else{ //if it's not in the list
		return 0;
	}
}

struct node sort(struct node *head){

}

void delete_list(struct node *head){
	struct node* temp;
	while(head!=NULL){
		temp =head;
		head = head->next;
		PROC_destroy(temp->process);
		free(temp);
	}
	free(head);
}

void print_list(struct node *head){
	struct node *cur = head;
	while(cur!=NULL){
		print_PROC(cur->process);
		cur=cur->next;
	}
}
