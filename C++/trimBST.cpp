/*
669. Trim a Binary Search Tree
https://leetcode.com/problems/trim-a-binary-search-tree/
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
        TreeNode *minValueNode(TreeNode *root)
        {
            while(root && root->left)
                root = root->left;
            return root;
        }
        TreeNode *deleteNode(TreeNode *root, int key)
        {
            if(!root)
                return NULL;
            if(key < root->val)
                root->left = deleteNode(root->left, key);
            else if(key > root->val)
                root->right = deleteNode(root->right, key);
            else
            {
                if(!root->left && !root->right)
                    return NULL;
                else if(!root->left)
                    return root->right;
                else if(!root->right)
                    return root->left;
                TreeNode *temp = minValueNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }            
            return root;
        }
    public:
        TreeNode* trimBST(TreeNode* root, int low, int high) 
        {
            if(!root)
                return root;
        
            queue<TreeNode*> q;
            q.push(root);
        
            while(!q.empty())
            {
                TreeNode* temp=q.front();
                q.pop();
            
                if(temp->val<low)
                {
                    temp->left=NULL;
                    root= deleteNode(root, temp->val);
                }
                else if(temp->left)
                    q.push(temp->left);
                
                if(temp->val>high)
                {
                    temp->right=NULL;
                    root= deleteNode(root, temp->val);
                }
                else if(temp->right)
                    q.push(temp->right);
            }
            return root;
        }
};
