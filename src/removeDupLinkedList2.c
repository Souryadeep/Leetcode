/*
	program:removeDupLinkedList2.c 
	compile with list2.c and include list2.h header from ../include
	leetcode: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
	Runtime: 4 ms, faster than 89.00% of C online submissions for Remove Duplicates from Sorted List II.
	Memory Usage: 6.6 MB, less than 33.00% of C online submissions for Remove Duplicates from Sorted List II
	CAUTION: This program has some memory leaks, working on that parrallely. Functionally, the program runs
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


struct ListNode* deleteDuplicates(struct ListNode* head){

    
    struct ListNode *sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    sentinel->val = 0;
    sentinel->next = head;
    struct ListNode *p = head;
    struct ListNode *prev = sentinel;
    
    while (p!=NULL){

        int flag = 0;
        while(p->next!=NULL && (p->next)->val == p->val){
             
	     p = p->next;
             flag = 1;
        }
        
        if (flag){
            prev->next = p->next;
        }else{
            prev = p;
        }
                
        p = p->next;
    }

    p = sentinel -> next;
    free(sentinel);

    return p;
}

int main(int argc, char* argv[]){

	struct ListNode *head = NULL;
        int i;
        for (i = 1; i < argc; i++) {
                head = prepend(head, atoi(argv[i]));
        }
	
	head = reverseList(head);	
	head = deleteDuplicates(head);

	print(head);
	deallocate_list(head);

	return 0;
}
