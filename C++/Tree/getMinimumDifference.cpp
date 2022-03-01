/*
530. Minimum Absolute Difference in BST
https://leetcode.com/problems/minimum-absolute-difference-in-bst/
*/
#include<iostream>
#include<vector>
#include<stack>
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

/*class Solution 
{   
    private:
        void inorderTraversal(TreeNode *root, vector<int> &inorderList)
        {
            if(!root)
                return;
            inorderTraversal(root->left, inorderList);
            inorderList.push_back(root->val);
            inorderTraversal(root->right, inorderList);
        }
    public:
        int getMinimumDifference(TreeNode* root) 
        {
            vector<int> inorderList;
            inorderTraversal(root, inorderList);
            int minimum = numeric_limits<int>::max();
            for(auto it = inorderList.begin(), jt = inorderList.begin() + 1; jt != inorderList.end(); it++, jt++)
                if(*jt - *it < minimum)
                    minimum = *jt - *it;
            return minimum;
        }
};*/

//Not my solution. Done in one pass
class Solution 
{
    int minimum = numeric_limits<int>::max(), prev = -1;
    public:
        int getMinimumDifference(TreeNode* root) 
        {
            if(root->left)
                getMinimumDifference(root->left);
            if(prev != -1)
                minimum = min(minimum, root->val - prev);
            prev = root->val;
            if(root->right)
                getMinimumDifference(root->right);
            return minimum;
        }
};
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(6);

    Solution solObj;
    int finalAnswer = solObj.getMinimumDifference(root);
    cout<<finalAnswer<<endl;
    return 0;
}