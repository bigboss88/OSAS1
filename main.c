#include "process.h"
#include "node.h"
#include <stdio.h>
int main(){
	struct Proc *proc1 = PROC_init('A',10,2,"Jacob");
	struct Proc *proc2 = PROC_init('B',4,3,"Megan");
	struct node *head = init(proc1);
	head =insert(head, proc2);
	print_list(head);
	delete_list(head);
}