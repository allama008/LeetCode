/*
129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

#include<iostream>
#include<vector>
#include<numeric>
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

class Solution 
{   
    private:
        void recursiveHelper(TreeNode *root, vector<int> &pathVector, int &totalSum)
        {
            if(!root)
                return;
            pathVector.push_back(root->val);
            if(!root->left && !root->right)
            {   
                int sum = 0, idx = 0;
                for(auto it = pathVector.rbegin(); it != pathVector.rend(); it++, idx++)
                    sum += *it * pow(10, idx);
                totalSum += sum;
                pathVector.pop_back();
                return;
            }
            recursiveHelper(root->left, pathVector, totalSum);
            recursiveHelper(root->right, pathVector, totalSum);
            pathVector.pop_back();
        }
    public:
        int sumNumbers(TreeNode* root) 
        {
            vector<int> path;
            int finalAnswer = 0;
            recursiveHelper(root, path, finalAnswer);
            return finalAnswer;
        }
};

int main()
{
    /*TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);*/

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(0);

    Solution solObj;
    cout<<solObj.sumNumbers(root)<<endl;
    return 0;
}