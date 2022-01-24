/*
113. Path Sum II
https://leetcode.com/problems/path-sum-ii/
*/

#include<iostream>
#include<vector>
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
        vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
        {
            vector<int> path;
            vector<vector<int>> paths;
            findPaths(root, targetSum, path, paths);
            return paths;
        }
    private:
        void findPaths(TreeNode *root, int targetSum, vector<int>& path, vector<vector<int>>& paths)
        {
            if(!root)
                return;
            path.push_back(root->val);
            if(targetSum - root->val == 0 && root->left == NULL && root->right == NULL)
                paths.push_back(path);
            findPaths(root->left, targetSum - root->val, path, paths);
            findPaths(root->right, targetSum - root->val, path, paths);
            path.pop_back();     
        }
    
};

int main()
{
    TreeNode *node = new TreeNode(5);
    node->left = new TreeNode(4);
    node->left->left = new TreeNode(11);
    node->left->left->left = new TreeNode(7);
    node->left->left->right = new TreeNode(2);
    node->right = new TreeNode(8);
    node->right->left = new TreeNode(13);
    node->right->right = new TreeNode(4);
    node->right->right->left = new TreeNode(5);
    node->right->right->right = new TreeNode(1);

    /*TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    //node->right = new TreeNode(3);*/

    Solution solObj;
    vector<vector<int>> finalAnswer = solObj.pathSum(node, 22);
    cout<<"[";
    for(int i = 0; i < finalAnswer.size(); i++)
    {
        cout<<"[";
        for(auto it = finalAnswer[i].begin(); it != finalAnswer[i].end(); it++)
            cout<<*it<<", ";
        cout<<"]";
    }
    cout<<"]";
    return 0;
}