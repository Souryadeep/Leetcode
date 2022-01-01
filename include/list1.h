#ifndef _LIST1_H_
#define _LIST1_H_

struct ListNode {
    struct ListNode *next;
    char val;
};

struct ListNode *prepend(struct ListNode *head, char val);

void print(struct ListNode *head);

/*
 * Deallocates all nodes (i.e., free() each node.)
 */
void deallocate_list(struct ListNode *head);

#endif /* #ifndef _LIST1_H_ */
