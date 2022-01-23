/*
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/
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

class Solution 
{
    public:
        bool recursiveHelper(TreeNode *p, TreeNode *q)
        {
            if(!p && !q)
                return true;
            if((p == NULL && q != NULL) || (p != NULL && q == NULL))
                return false;
            if(p->val != q->val)
                return false;
            return recursiveHelper(p->left, q->right) && recursiveHelper(p->right, q->left);
        }
        bool isSymmetric(TreeNode* root) 
        {
            if(!root->left && !root->right)
                return true;
            return recursiveHelper(root->left, root->right);
        }
};

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(2);
    node->left->left = new TreeNode(3);
    node->right->right = new TreeNode(3);
    node->left->right = new TreeNode(4);
    node->right->left = new TreeNode(4);

    /*TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(2);
    node->right->right = new TreeNode(3);
    node->left->right = new TreeNode(3);*/

    Solution solObj;
    cout<<boolalpha<<solObj.isSymmetric(node)<<endl;
    return 0;
}