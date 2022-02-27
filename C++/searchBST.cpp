/*
700. Search in a Binary Search Tree
https://leetcode.com/problems/search-in-a-binary-search-tree/
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
        TreeNode* searchBST(TreeNode* root, int val) 
        {
            if(!root)
                return NULL;
            if(root->val > val)
                return searchBST(root->left, val);
            else if(root->val < val)
                return searchBST(root->right, val);
            else
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

    Solution solObj;
    TreeNode *finalAnswer = solObj.searchBST(root, 2);
    vector<int> finalAnswerList = inorderTraversal(finalAnswer);
    for(auto it = finalAnswerList.begin(); it != finalAnswerList.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}