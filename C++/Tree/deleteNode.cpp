/*
450. Delete Node in a BST
https://leetcode.com/problems/delete-node-in-a-bst/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<limits>
#include<cstdlib>
#include"inorderTraversal.h"
using namespace std;

/**
 * Definition for a binary tree node.
*/
/*
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/
class Solution 
{
    private:
        TreeNode* minValueNode(TreeNode *root)
        {
            while(root && root->left)
                root = root->left;
            return root;
        }
    public:
        TreeNode* deleteNode(TreeNode* root, int key) 
        {
            if(!root)
                return root;
            if(key < root->val)
                root->left = deleteNode(root->left, key);
            else if(key > root->val)
                root->right = deleteNode(root->right, key);
            else
            {
                if(!root->left && !root->right)
                    return NULL;
                else if(!root->left)
                {
                    TreeNode *temp = root->right;
                    //free(root); LEETCODE NOT ACCEPTING free();
                    return temp;
                }
                else if(!root->right)
                {
                    TreeNode *temp = root->left;
                    //free(root); LEETCODE NOT ACCEPTING free();
                    return temp;
                }

                TreeNode *temp = minValueNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
            return root;
        }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preDeleteList = inorderTraversal(root);
    for(int x : preDeleteList)
        cout<<x<<" ";
    cout<<endl;

    Solution solObj;
    TreeNode *finalAnswerNode = solObj.deleteNode(root, 5);
    vector<int> finalAnswerList = inorderTraversal(finalAnswerNode);
    for(int x : preDeleteList)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
