/*
563. Binary Tree Tilt
https://leetcode.com/problems/binary-tree-tilt/
*/

#include<iostream>
#include<vector>
#include<math.h>
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

//NOT WORKING
/*class Solution 
{
    private:
        void recursiveHelper(TreeNode *root, int &sum)
        {
            if(!root)
                return;
            recursiveHelper(root->left, sum);
            recursiveHelper(root->right, sum);
            //cout<<((!root->left) ? 0:root->left->val)<<" "<<((!root->right) ? 0:root->right->val)<<" ";
            sum += abs(((!root->left) ? 0:root->left->val) - ((!root->right) ? 0:root->right->val));
            cout<<sum<<" ";
        }
    public:
        int findTilt(TreeNode* root) 
        {
            int initSum = 0;
            recursiveHelper(root, initSum);
            return initSum;
        }
};*/

//ANOTHER SOLUTION BY ME
class Solution 
{
    private:
        int recursiveHelper(TreeNode *root, int &sum)
        {
            if(!root)
                return 0;
            int left = recursiveHelper(root->left, sum);
            int right = recursiveHelper(root->right, sum);
            int tempSum = left + right + root->val;
            root->val = abs(left - right);
            sum += root->val;
            return tempSum;
        }
    public:
        int findTilt(TreeNode* root) 
        {
            int initSum = 0;
            recursiveHelper(root, initSum);
            return initSum;
        }
};


int main()
{
    /*TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);*/

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(9);
    root->right->right = new TreeNode(7);

    Solution solObj;
    int finalAnswer = solObj.findTilt(root);
    cout<<finalAnswer<<endl;
    return 0;
}