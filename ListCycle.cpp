#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode listnode;

listnode* listnode_new(int val) {

	listnode* node = (listnode *) malloc(sizeof(listnode));

	node->val = val;
	node->next = NULL;

	return node;
}

listnode* detectCycle(listnode* A){
	return NULL;
}

void insertAfter(listnode **head, int val) {
	listnode *node = listnode_new(val);
	listnode *p = *head;

	printf("insert %d\n", node->val);

	if (*head == NULL) {
		*head = node;
		return;
	}

	while( p->next != NULL ) {
		p = p->next;
	}

	p->next = node;
}

void printList(listnode *head) {
	printf("%p\n", head);
	while(head != NULL) {
		printf(" %d\n", head->val);
		head = head->next;
	}
}

int main() {

	int a[] = {1, 2, 3, 4, 5, 6};
	int len = sizeof(a)/sizeof(a[0]);

	listnode *head = NULL;

	for (int i = 0; i < len; i++)
	       insertAfter(&head, a[i]);


	printf("print\n");

	printList(head);

	return 0;
}
