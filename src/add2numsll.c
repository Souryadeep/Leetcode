/*
	program: add2numsll.c
	leetcode problem: https://leetcode.com/problems/add-two-numbers/

	Runtime: 21 ms, faster than 55.27% of C online submissions for Add Two Numbers.
	Memory Usage: 7.9 MB, less than 6.48% of C online submissions for Add Two Numbers.

	NOTE: this program has memory leaks. feel free to fix them 
*/

#include <stdio.h>
#include <stdlib.h>


struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){


    int sum, carry;
    sum = carry = 0;
    
    struct ListNode* sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* runner;
    struct ListNode* ptr = sentinel;
    
    while (l1 != NULL && l2 != NULL){
        
        sum = l1->val + l2->val + carry;
        runner = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        if (ptr == sentinel)
            sentinel->next = runner;
        else
            ptr->next = runner;
        
        runner->val = sum%10;
        ptr = runner;
        
        carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
        
    }
    
    while (l1 != NULL){
        
        sum = l1->val + carry;
        runner = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        runner->val = sum%10;
        ptr->next = runner;
        ptr = runner;
        
        carry = sum/10;
        l1 = l1->next;
        
    }
    
    while (l2 != NULL){
        
        sum = l2->val + carry;
        runner = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        runner->val = sum%10;
        ptr->next = runner;
        ptr = runner;
        
        carry = sum/10;
        l2 = l2->next;
        
    }
    
    if (carry != 0){
        
        runner = (struct ListNode*)malloc(sizeof(struct ListNode));
        runner->val = carry;
        ptr->next = runner;
    }
    
    runner->next = NULL;
    return sentinel->next;
}


int main(int argc, char *argv[]){
    
	
	struct ListNode* l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode* l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode* result;

	printf("Enter the first number: ");
	int num1;
	scanf(" %d",&num1);

	
	printf("Enter the second number: ");
	int num2;
	scanf(" %d",&num2);
	
	struct ListNode* node;
	struct ListNode* ptr = l1;
	while(num1){
	
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->val = num1%10;

		if (ptr == l1)
			l1->next = node;
		else
			ptr->next = node;

		ptr = node;
		num1/=10;

	}

	ptr = l2;
	while(num2){
	
		node = (struct ListNode *)malloc(sizeof(struct ListNode));
		node->val = num2%10;

		if (ptr == l1)
			l1->next = node;
		else
			ptr->next = node;

		ptr = node;
		num2/=10;

	}

	result = addTwoNumbers(l1->next, l2->next);	

	while (result){
		
			printf("%d", result->val);
			result = result->next;
	}
	printf("\n");

    return 0;
}

