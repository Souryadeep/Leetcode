/*
	program: swapPairs.c
	leetcode: https://leetcode.com/problems/swap-nodes-in-pairs/
	Runtime: 0 ms, faster than 100.00% of C online submissions for Swap Nodes in Pairs
	Memory Usage: 6 MB, less than 18.87% of C online submissions for Swap Nodes in Pairs
	use with list2.h and list2.c

*/


#include <stdio.h>
#include <stdlib.h>
#include "list2.h"



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

struct ListNode* swapPairs(struct ListNode* head){

    struct ListNode *sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    sentinel->val = 0;
    sentinel->next = head;
    
    struct ListNode *prev = sentinel;
    struct ListNode *curr = head;
    
    while(curr != NULL && curr->next != NULL){
        
        struct ListNode *temp = curr->next;
        
        curr->next = (curr->next)->next;
        prev->next = temp;
        temp ->next = curr;
        
        prev = curr;
        curr = curr->next;
        
    }
    
    return sentinel->next;
}

int main(int argc,char *argv[]){

	
	struct ListNode *head = NULL;
        int i;
        for (i = 1; i < argc; i++) {
                head = prepend(head, atoi(argv[i]));
        }
	
	head = reverseList(head);	
	head = swapPairs(head);

	print(head);
	deallocate_list(head);
	
	return 0;
}
