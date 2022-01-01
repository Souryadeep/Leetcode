//program: revereselist.c
//leetcode problem: https://leetcode.com/problems/reverse-linked-list/
/*
	use header list1.h from ../include
	compile with list1.c which has list1.h function implementations
	Runtime: 0 ms, faster than 100.00% of C online submissions for Reverse Linked List.
	Memory Usage: 6.2 MB, less than 90.23% of C online submissions for Reverse Linked List.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

struct ListNode* reverseList(struct ListNode* head){

	struct ListNode *prev = NULL;
	struct ListNode *current = head;
	struct ListNode *next = NULL;
    
	while(current){
        	next = current->next;
        	current->next = prev;
        	prev = current;
        	current = next;
    	}
    
	return prev;

}

int main(int argc, char* argv[]){

	struct ListNode *head = NULL;
        int i;
        for (i = 1; i < argc; i++) {
                head = prepend(head, *argv[i]);
        }

        print(head);
        deallocate_list(head);

}
