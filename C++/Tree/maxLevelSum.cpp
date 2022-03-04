/*
1161. Maximum Level Sum of a Binary Tree
https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
*/

#include<iostream>
#include<vector>
#include<algorithm>
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
        void recursiveHelper(TreeNode *root, int depth, vector<int> &levelOrder)
        {
            if(!root)
                return;
            if(depth == levelOrder.size())
                levelOrder.resize(levelOrder.size() + 1);
            levelOrder[depth] += root->val;
            recursiveHelper(root->left, depth+1, levelOrder);
            recursiveHelper(root->right, depth+1, levelOrder);
        }
    public:
        int maxLevelSum(TreeNode* root) 
        {
            vector<int> levelOrderSum;
            recursiveHelper(root, 0, levelOrderSum);
            return distance(levelOrderSum.begin(), max_element(levelOrderSum.begin(), levelOrderSum.end())) + 1;
        }
};


// Same solution as original above. Optimized by taking levelOrder as class member;
/*
class Solution 
{
    private:
        vector<int> levelOrder;
        void recursiveHelper(TreeNode *root, int depth)
        {
            if(!root)
                return;
            if(depth == levelOrder.size())
                levelOrder.resize(levelOrder.size() + 1);
            levelOrder[depth] += root->val;
            recursiveHelper(root->left, depth+1);
            recursiveHelper(root->right, depth+1);
        }
    public:
        int maxLevelSum(TreeNode* root) 
        {
            //vector<int> levelOrder;
            recursiveHelper(root, 0);
            return distance(levelOrder.begin(), max_element(levelOrder.begin(), levelOrder.end())) + 1;
        }
};
*/

//Same logic as above. Picked up from internet
/*
class Solution 
{
    private:
        vector<int> sums;
        void dfs(TreeNode* r, size_t lvl) 
        {
            if (r != nullptr) 
            {
                sums.resize(max(sums.size(), lvl));
                sums[lvl - 1] += r->val;
                dfs(r->left, lvl + 1);
                dfs(r->right, lvl + 1);
            }
        }
    public:
        int maxLevelSum(TreeNode* r) 
        {
            dfs(r, 1);
            return distance(begin(sums), max_element(begin(sums), end(sums))) + 1;
        }
};
*/
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution solObj;
    cout<<solObj.maxLevelSum(root)<<endl;
    return 0;
}