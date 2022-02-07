/*
	program: bstinorder.cpp
	leetcode: https://leetcode.com/problems/binary-tree-inorder-traversal/
	Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal
	Memory Usage: 8.4 MB, less than 38.96% of C++ online submissions for Binary Tree Inorder Traversal

*/


#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     //TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     //TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {       
        vector<int> inorder;
        traverse(root,inorder);
        return inorder;
    }
    
    void traverse(TreeNode* root, vector<int>& inorder){
        
        if(root){
            traverse(root->left,inorder);
            inorder.push_back(root->val);
            traverse(root->right,inorder);
        }
    }
};

TreeNode *insert(int x, TreeNode *node)
{
    if (node == NULL) {
        node = new TreeNode(x);
    }
    else if (x < node->val) {
        node->left = insert(x, node->left);
    }
    else if (x > node->val) {
        node->right= insert(x, node->right);
    }
    else {
        // x is in the tree already.
    }

    return node;
}

int main(int argc, char* argv[]){

	
	if(argc == 1){
		cout << "usage: ./test <elements of tree>" << endl;
		exit(1);
	}
			  
	TreeNode* root = NULL;		  
	for (int i=1;i<argc;++i){
		root = insert(stoi(argv[i]),root);
	}

	Solution s;
	vector<int> inorder = s.inorderTraversal(root);

	for(auto it = inorder.begin();it!=inorder.end();++it)
		cout << *it << " ";
	cout << endl;

	return 0;
}
