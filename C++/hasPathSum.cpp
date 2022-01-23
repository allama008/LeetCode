/*
112. Path Sum
https://leetcode.com/problems/path-sum/
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
    bool recursiveHelper(TreeNode* root, int targetSum)
    {
        if(!root)
            return false;
        if(targetSum - root->val == 0 && root->left == NULL && root->right == NULL)
            return true;
        if(targetSum - root->val != 0 && root->left == NULL && root->right == NULL)
            return false;
        /*bool tempAnswer = recursiveHelper(root->left, targetSum - root->val);
        if(tempAnswer) return true;
        tempAnswer = recursiveHelper(root->right, targetSum - root->val);
        if(tempAnswer) return true;
        return false;*/
        return recursiveHelper(root->left, targetSum - root->val) || recursiveHelper(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return false;
        bool answer = recursiveHelper(root, targetSum);
        return answer;
    }
};

int main()
{
    /*TreeNode *node = new TreeNode(5);
    node->left = new TreeNode(4);
    node->left->left = new TreeNode(11);
    node->left->left->left = new TreeNode(7);
    node->left->left->right = new TreeNode(2);
    node->right = new TreeNode(8);
    node->right->left = new TreeNode(13);
    node->right->right = new TreeNode(4);
    node->right->right->right = new TreeNode(1);*/

    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    //node->right = new TreeNode(3);

    Solution solObj;
    bool finalAnswer = solObj.hasPathSum(node, 0);
    cout<<boolalpha<<finalAnswer<<endl;
    return 0;
}