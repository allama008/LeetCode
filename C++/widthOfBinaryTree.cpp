/*
662. Maximum Width of Binary Tree
https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

#include<iostream>
#include<vector>
#include<queue>
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
    public:
        int widthOfBinaryTree(TreeNode* root) 
        {
            if(!root)
                return 0;
            int res = 1;
            queue<pair<TreeNode*, int>> DFSQueue;
            DFSQueue.push({root, 0});

            while(!DFSQueue.empty())
            {
                int count = DFSQueue.size();
                int start = DFSQueue.front().second;
                int end = DFSQueue.back().second;

                res = max(res, end - start + 1);

                for(int i = 0; i < count; i++)
                {
                    pair<TreeNode*, int> p = DFSQueue.front();
                    int idx = p.second - start;
                    DFSQueue.pop();
                    if(p.first->left)
                        DFSQueue.push({p.first->left, (long long)2 * idx + 1});
                    if(p.first->right)
                        DFSQueue.push({p.first->right, (long long)2 * idx + 2});
                }
            }
        return res;
        }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(5);

    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);

    Solution solObj;
    int finalAnswer = solObj.widthOfBinaryTree(root);
    cout<<finalAnswer<<endl;
    return 0;
}