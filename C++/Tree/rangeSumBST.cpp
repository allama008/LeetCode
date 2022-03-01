/*
938. Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/
*/
#include<iostream>
#include<vector>
#include<stack>
#include<limits>
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

//BEKAAR SOLUTION BY ME
/*class Solution 
{
    bool flag = false;
    int sum = 0;
    public:
        int rangeSumBST(TreeNode* root, int low, int high) 
        {
            if(root->left)
                rangeSumBST(root->left, low, high);
            if(root->val == low)
                flag = true;
            if(flag)
                sum += root->val;
            if(root->val == high)
                flag = false;
            if(root->right)
                rangeSumBST(root->right, low, high);
            return sum;
        }
};*/


class Solution 
{
    public:
        int rangeSumBST(TreeNode* root, int low, int high) 
        {
            if(!root)
                return 0;
            if(root->val < low)
                return rangeSumBST(root->right, low, high);
            else if(root->val > high)
                return rangeSumBST(root->left, low, high);
            return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
        }
};

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);

    Solution solObj;
    int finalAnswer = solObj.rangeSumBST(root, 7, 15);
    cout<<finalAnswer<<endl;
    return 0;
}