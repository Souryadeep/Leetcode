/*
	program: hasCycle.c
	leetcode: https://leetcode.com/problems/linked-list-cycle/
	Runtime: 8 ms, faster than 86.73% of C online submissions for Linked List Cycle
	Memory Usage: 7.9 MB, less than 46.76% of C online submissions for Linked List Cycle
	WARNING: please modify the main function to make a cyclic linked list. Functionally, hasCycle() works correctly

*/


#include <stdio.h>
#include <stdlib.h>
#include "list2.h"
#include <stdbool.h>

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

bool hasCycle(struct ListNode *head) {
    
    struct ListNode *run1 = head;
    struct ListNode *run2 = head;

    bool cycle = false;
    
    if(run1== NULL || run1->next == NULL)
        return false;
    
    while(run1){
        if(run1->next!=NULL)
            run1 = run1 -> next -> next;
        else
            run1 = run1 -> next;
        
        run2 = run2 -> next;
        if (run1 == run2){
            cycle = true;
            break;
        }
               
    }
    
    return cycle;
}

int main(int argc, char* argv[]){

	
	struct ListNode *head = NULL;
        int i;
        for (i = 1; i < argc; i++) {
                head = prepend(head, atoi(argv[i]));
        }
	
	head = reverseList(head);	

	bool cycle = hasCycle(head);

	cycle == true?printf("Linked list has cycle\n"):printf("Linked list does not have cycle\n");
	
	return 0;


}
