#include <stdio.h>
#include <string.h>
#include "list1.h"
#include <stdlib.h>
#include <assert.h>

struct ListNode *prepend(struct ListNode *head, char val){
	
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	if (node == NULL)
        	return NULL;
	
	node->val = val;
	node->next = head;
	
	return node;
}

void print (struct ListNode *head){
	struct ListNode *node = head;
	while (node) {

		printf("->[%c]", node->val);
		node = node->next;
	}
	printf("\n");

}

struct ListNode *remove_front(struct ListNode *head)
{
       struct ListNode *rest = NULL;
       if (head) {
              rest = head->next;
              free(head);
       }
       return rest;
}


void deallocate_list(struct ListNode *head){

	while (head) {
		head = remove_front(head);
	}
	assert (head == NULL);
}

