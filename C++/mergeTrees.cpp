/*
617. Merge Two Binary Trees
https://leetcode.com/problems/merge-two-binary-trees/
*/

#include<iostream>
#include"inorderTraversal.h"
using namespace std;

/**
 * Definition for a binary tree node.

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; */

class Solution 
{
    public:
        TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
        {
            if(root1 && root2)
            {
                root1->val += root2->val;
                root1->left = mergeTrees(root1->left, root2->left);
                root1->right = mergeTrees(root1->right, root2->right);
            }
            else 
                return root1 ? root1 : root2;
            return root1;
            
        }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(3);
    node1->left->left = new TreeNode(5);
    node1->right = new TreeNode(2);

    TreeNode *node2 = new TreeNode(2);
    node2->left = new TreeNode(1);
    node2->left->right = new TreeNode(4);
    node2->right = new TreeNode(3);
    node2->right->right = new TreeNode(7);

    Solution solObj;
    TreeNode *finalAnswer = solObj.mergeTrees(node1, node2);
    vector<int> finalAnswerList = inorderTraversal(finalAnswer);
    for(auto it = finalAnswerList.begin(); it != finalAnswerList.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
    return 0;
}