/*
111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/
*/

#include<iostream>
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

class Solution 
{   
    private:
        int minDepthHelper(TreeNode *root, int depth)
        {
            if(!root)
                return numeric_limits<int>::max();
            if(!(root->left) && !(root->right))
                return depth;              
            return min(minDepthHelper(root->left, depth + 1), minDepthHelper(root->right, depth + 1));
        }
    public:
        int minDepth(TreeNode* root) 
        {
            if(!root)
                return 0;
            return minDepthHelper(root, 1);
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
    node->left = new TreeNode(2);
    node->left->right = new TreeNode(3);
    node->right = new TreeNode(2);
    node->left->left = new TreeNode(3);
    node->left->left->right = new TreeNode(4);
    node->left->left->left = new TreeNode(4);

    /*TreeNode *node = new TreeNode(2);
    node->right = new TreeNode(3);
    node->right->right = new TreeNode(4);
    node->right->right->right = new TreeNode(5);
    node->right->right->right->right = new TreeNode(6);*/

    Solution solObj;
    cout<<solObj.minDepth(node)<<endl;
    return 0;
}