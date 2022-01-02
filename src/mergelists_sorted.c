/*
	program: mergelists_sorted.c 
	leetcode problem: https://leetcode.com/problems/merge-two-sorted-lists/
	use header list1.h from ../include
        compile with list1.c which has list1.h function implementations
        Runtime: 5 ms, faster than 15.00% of C online submissions for Merge Two Sorted Lists
        Memory Usage: 6.2 MB, less than 39.06% of C online submissions for Merge Two Sorted Lists
	Recursive approach used, iterative approach is expected to give better space complexity. recursive approach gives O(m+n) space complexity
*/

#include <stdio.h>
#include <assert.h>
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


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

	//base case for list1 and list2
	//recursive approach used
	if (list1 == NULL)
        	return list2;
    	else if (list2 == NULL)
        	return list1;
    
    	else if (list1->val < list2->val){
        	list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    	}
    	else{
        	list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    	}

	
}


int main(int arg, char *argv[]){

	
	struct ListNode *head1 = NULL;
	struct ListNode *head2 = NULL;

	printf("Enter length of first list: ");
	int list1;
	scanf(" %d",&list1);

	printf("Enter length of second list: ");
	int list2;
	scanf(" %d",&list2);

	int temp;
	printf("Enter the elements of list1: ");
        for (int i=0;i<list1;++i){
                scanf(" %d",&temp);
		head1 = prepend(head1,temp);	
        }
	head1 = reverseList(head1);

	printf("Enter elements of list2: ");
        for (int i=0;i<list2;++i){
                scanf(" %d",&temp);
		head2 = prepend(head2,temp);	
        }
	head2 = reverseList(head2);
	 
	 print(head1);
	 print(head2);

	struct ListNode *head = mergeTwoLists(head1,head2);

        print(head);
        deallocate_list(head);

	return 0;


}
