/*
226. Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include"inorderTraversal.h"
using namespace std;

/**
 * Definition for a binary tree node.
*/
/*struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};*/

class Solution 
{
    public:
        TreeNode* invertTree(TreeNode* root) 
        {
            if(!root)
                return NULL;
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
            return root;
        }
};

int main()
{
    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    vector<int> treeTraversal = inorderTraversal(root);
    for(auto it = treeTraversal.begin(); it != treeTraversal.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    Solution solObj;
    TreeNode *finalAnswer = solObj.invertTree(root);

    vector<int> finalAnswerList = inorderTraversal(finalAnswer);
    for(auto it = finalAnswerList.begin(); it != finalAnswerList.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}