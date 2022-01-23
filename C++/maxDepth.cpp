/*
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

#include<iostream>
#include<algorithm>
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
        int recursiveHelper(TreeNode *root, int depth)
        {
            if(!root)
                return depth - 1;
            return max(recursiveHelper(root->left, depth + 1), recursiveHelper(root->right, depth + 1));
        }
        int maxDepth(TreeNode* root) 
        {
            return recursiveHelper(root, 1);
        }
};

int main()
{
    /*TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);*/

    TreeNode *node = new TreeNode(1);
    node->right = new TreeNode(2);

    Solution solObj;
    cout<<solObj.maxDepth(node)<<endl;
    return 0;
}