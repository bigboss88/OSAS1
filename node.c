#include <stdlib.h>
#include <string.h>
#include "process.h"
struct node{
	struct Proc *process;
	struct node *next;
}node;

struct node* init(struct Proc *P){
	 struct node *n = malloc(sizeof(struct node));
	 n->process=P;
	 n->next=NULL;
	 return n;
}
struct node* insert(struct node *head, struct Proc *P){
	struct node *cur = head;
	struct node *prev = NULL;
	while(cur!=NULL){
		if(P->dur <= cur->process->dur){ //found location to add
			break;
		}
		prev=cur;
		cur=cur->next;
	}

	if(prev==NULL){ // at front
		struct node *nhead = init(P);
		nhead->next = cur;
		head = nhead; 
		return head;
	}
	else if(cur==NULL){ //at end
		prev->next = init(P);
		return head;
	}

	else{ //Somewhere in middle
		struct node *nnode = init(P);
		prev->next = nnode;
		nnode->next = cur;
		return head;
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
}

void print_list(struct node *head){
	struct node *cur = head;
	while(cur!=NULL){
		print_PROC(cur->process);
		cur=cur->next;
	}
}