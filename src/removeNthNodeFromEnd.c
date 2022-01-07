/*
	program: removeNthFromEnd.c
	leetcode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
	Runtime: 3 ms, faster than 57.94% of C online submissions for Remove Nth Node From End of List
	Memory Usage: 5.7 MB, less than 99.08% of C online submissions for Remove Nth Node From End of List

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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode* sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    sentinel->next = head;
    sentinel->val = 0;
    struct ListNode *prev = sentinel;
    struct ListNode *curr = sentinel;
    
    for(int i=1;i<=n;++i)
        curr = curr->next;
    
    while(curr){
        
        if (curr->next==NULL){
             prev->next = (prev->next)->next;
             curr = curr->next;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }
    }
        
    return sentinel->next;   
}

int main(int argc, char* argv[]){

	struct ListNode *head = NULL;
        int i;
        for (i = 1; i < argc; i++) {
                head = prepend(head, atoi(argv[i]));
        }

	printf("Select which node from the end to remove: ");
	int rem;
	scanf("%d",&rem);
	
	head = reverseList(head);	
	struct ListNode *res = removeNthFromEnd(head,rem);
	print(res);
	deallocate_list(res);

	return 0;
}
