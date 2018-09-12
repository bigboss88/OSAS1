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
#endif