/*
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

#include<iostream>
#include<vector>
using namespace std;

/**
 * Definition for a binary tree node.
*/
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
    public:
        void recursiveHelper(TreeNode* root, vector<int>& inorderList)
        {
            if(!root)
                return;
            recursiveHelper(root->left, inorderList);
            inorderList.push_back(root->val);
            recursiveHelper(root->right, inorderList);
        }
        vector<int> inorderTraversal(TreeNode* root) 
        {   
            vector<int> inorderList;
            recursiveHelper(root, inorderList);
            return inorderList;
        }
};

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    Solution solObj;
    vector<int> finalAnswer = solObj.inorderTraversal(node);
    for(auto iter = finalAnswer.begin(); iter != finalAnswer.end(); iter++)
        cout<<*iter<<" ";
    cout<<endl;
    return 0;
}