//node.h

#ifndef node_h
#define node_h
struct node{
	char* user;
	char job;
	int arr;
	int dur;
	struct node *next;
}node;
struct node* init(char *u,char j, int a,int d);
struct node* insert(struct node *head, struct node *nnode);
int pop(struct node **head, char job);
void delete_list(struct node *head);
void print_list(struct node *head);
#endif