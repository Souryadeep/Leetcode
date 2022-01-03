/*
	program:removeDupLinkedList.c 
	compile with list2.c and include list2.h header from ../include
	leetcode: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
	Runtime: 5 ms, faster than 29.88% of C online submissions for Remove Duplicates from Sorted List
	Memory Usage: 6.4 MB, less than 66.15% of C online submissions for Remove Duplicates from Sorted List

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

    struct ListNode *p = head;
    while (p!=NULL){

        struct ListNode *temp = p;
        while(p->next!=NULL && (p->next)->val == p->val)
            p = p->next;
        temp->next = p->next;
        p = p->next;
    }

    return head;
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
