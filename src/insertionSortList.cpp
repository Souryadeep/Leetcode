/*
	program: insertionSortList.cpp
	leetcode: https://leetcode.com/problems/insertion-sort-list/
	Runtime: 83 ms, faster than 14.72% of C++ online submissions for Insertion Sort List
	Memory Usage: 10.2 MB, less than 6.43% of C++ online submissions for Insertion Sort List
*/

#include <iostream>
using namespace std;

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

struct ListNode* add(ListNode* head,int val){

	struct ListNode *node = new ListNode(val,head);
	if (node == NULL)
		  return NULL;
	return node;
}

int main(int argc, char* argv[]){

	cout << "Enter size of list: ";
	int size;

	cin >> size;
	
	cout << "Enter the elements of the list: \n";
	ListNode *head = new ListNode();

	for(auto i = 0;i<size;++i){
		int temp;
		cin >> temp;
		head = add(head,temp);	
	}
	Solution obj;
	head = obj.insertionSortList(head);
	head = head->next;
	for(auto i = 0;i<size;++i){
		cout << head->val <<  " ";
		head = head->next;
	} 	
	cout << endl;

	return 0;
}
