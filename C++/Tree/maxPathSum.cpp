/*
124. Binary Tree Maximum Path Sum
https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
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
        int helperFunction(TreeNode *root, int &sum)
        {
            if(!root)
                return 0;
            int left = helperFunction(root->left, sum) + root->val;
            int right = helperFunction(root->right, sum) + root->val;
            sum = max({left + right - root->val, sum, root->val, left, right});
            return max({left, right, root->val});
        }
    public:
        int maxPathSum(TreeNode* root) 
        {
            int finalAnswer = INT_MIN;
            helperFunction(root, finalAnswer);
            return finalAnswer;
        }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    /*TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);*/

    Solution solObj;
    cout<<solObj.maxPathSum(root)<<endl;
    return 0;
}
