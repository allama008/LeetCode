/*
543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/
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
        int recursiveHelper(TreeNode* root, int &depth)
        {
            if(!root)
                return 0;
            int left = recursiveHelper(root->left, depth);
            int right = recursiveHelper(root->right, depth);
            depth = max(depth, left + right);
            return max(left, right) + 1;
        }
        int diameterOfBinaryTree(TreeNode* root) 
        {
            int d = 0;
            recursiveHelper(root, d);
            return d;
        }
};

int main()
{
    /*TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);*/

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);

    Solution solObj;
    int finalAnswer = solObj.diameterOfBinaryTree(root);
    cout<<finalAnswer<<endl;
    return 0;
}