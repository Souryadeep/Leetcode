#include <iostream>


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if(head->next == NULL)
            return head;

        ListNode *sentenial = new ListNode();
        ListNode *newlist = new ListNode(head->val);
        sentenial->next = newlist;
        head = head->next;

        while(head){

            ListNode *iter = sentenial;
            while(iter->next && head->val > iter->next->val)
                iter = iter->next;

            ListNode *newnode = new ListNode(head->val);
            newnode->next = iter->next;
            iter->next = newnode;

            head = head->next;
        }
        return sentenial->next;
    }
};


int main(int argc, char*argv){



	return 0;
}
