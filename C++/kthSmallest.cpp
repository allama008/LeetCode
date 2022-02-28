/*
230. Kth Smallest Element in a BST
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<limits>
#include<cstdlib>
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
    private:
        void inorderTraversal(TreeNode *root, vector<int> &inorderList)
        {
            if(!root)
                return;
            inorderTraversal(root->left, inorderList);
            inorderList.push_back(root->val);
            inorderTraversal(root->right, inorderList);
        }
    public:
        int kthSmallest(TreeNode* root, int k) 
        {   
            vector<int> inorderList;
            inorderTraversal(root, inorderList);
            return inorderList[k-1];
        }
};