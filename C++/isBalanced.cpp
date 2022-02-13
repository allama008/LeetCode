/*
110. Balanced Binary Tree
https://leetcode.com/problems/balanced-binary-tree/
*/

#include<iostream>
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


// Original approach which is not working
/*class Solution 
{
    public:
        int recursiveHelper(TreeNode *root, int depth)
        {
            if(!root)
                return depth - 1;
            cout<<recursiveHelper(root->left, depth + 1)<<"*"<<recursiveHelper(root->right, depth + 1)<<"+"<<endl;
            if(abs(recursiveHelper(root->left, depth + 1) - recursiveHelper(root->right, depth + 1)) > 1)
                return 0;
            else
                return 1;
        }
        bool isBalanced(TreeNode* root) 
        {
            int boolVar = -1;
            boolVar = recursiveHelper(root, 1);
            //cout<<boolVar<<endl;
            if(boolVar == 1)
                return true;
            else
                return true;
        }
};*/

// My modified solution which is working
class Solution 
{
    private:
        bool ans = true;
        int recursiveHelper(TreeNode *root, int depth)
        {
            if(!root)
                return depth - 1;
            if(!ans)
                return 0;
            int leftSubtree = recursiveHelper(root->left, depth + 1);
            int rightSubtree = recursiveHelper(root->right, depth + 1);
            if(abs(leftSubtree - rightSubtree) > 1)
                ans = false;
            return max(leftSubtree, rightSubtree);
        }
    public:
        bool isBalanced(TreeNode* root) 
        {
            recursiveHelper(root, 1);
            return ans;
        }
};

// Solution from Discussion after failing to do it
/*
class Solution 
{
    private:
        bool ans = true;
        int checkBalance(TreeNode *root)
        {
            if(!root)
                return 0;
            if(!ans)
                return 0;
            int leftSubtree = checkBalance(root->left);
            int rightSubtree = checkBalance(root->right);
            if(abs(leftSubtree - rightSubtree) > 1)
                ans = false;
            return max(leftSubtree, rightSubtree) + 1;
        }
    public:
        bool isBalanced(TreeNode* root) 
        {
            checkBalance(root);
            return ans;
        }
};*/

int main()
{
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);

    /*TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->left->right = new TreeNode(3);
    node->right = new TreeNode(2);
    node->left->left = new TreeNode(3);
    node->left->left->right = new TreeNode(4);
    node->left->left->left = new TreeNode(4);*/

    Solution solObj;
    cout<<boolalpha<<solObj.isBalanced(node)<<endl;
    return 0;
}