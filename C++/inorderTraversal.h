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

