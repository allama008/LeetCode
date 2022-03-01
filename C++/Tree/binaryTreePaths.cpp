/*
257. Binary Tree Paths
https://leetcode.com/problems/binary-tree-paths/
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
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

//Revisiting the Question on 28th February 2022. New Approach. Performed slightly better.
class Solution 
{
    private:
        void recursiveHelper(TreeNode *root, vector<int> &pathVector, vector<string> &strVector)
        {
            if(!root)
                return;
            pathVector.push_back(root->val);
            if(!root->left && !root->right)
            {
                string str;
                for(auto i : pathVector)
                    str = str + to_string(i) + "->";
                str = str.substr(0, str.size()-2);
                strVector.push_back(str);
                pathVector.pop_back();
                return;
            }
            recursiveHelper(root->left, pathVector, strVector);
            recursiveHelper(root->right, pathVector, strVector);
            pathVector.pop_back();
        }
    public:
        vector<string> binaryTreePaths(TreeNode* root) 
        {
            vector<int> paths;
            vector<string> returnVector;
            recursiveHelper(root, paths, returnVector);
            return returnVector;
        }
};

//WORK AS ON 24th January 2022. Right below code is working.
/*
class Solution 
{
    public:
        vector<string> stringPath;
        vector<string> binaryTreePaths(TreeNode* root) 
        {
            recursiveHelper(root, "");
            return stringPath;
        }
    private:
        void recursiveHelper(TreeNode *root, string str)
        {
            if(!root)
                return;
            if(!(root->left) && !(root->right))
            {
                str.append(to_string(root->val));
                stringPath.push_back(str);
                return;
            }
            str.append(to_string(root->val));
            str.append("->");
            recursiveHelper(root->left, str);
            recursiveHelper(root->right, str);
        }
};
*/

/*class Solution 
{
    public:
        vector<string> binaryTreePaths(TreeNode* root) 
        {
            vector<int> path;
            vector<string> stringPath;
            recursiveHelper(root, path, stringPath);
            return stringPath;
        }
    private:
        void recursiveHelper(TreeNode *root, vector<int>& path, vector<string>& stringPath)
        {
            if(!root)
                return;
            path.push_back(root->val);
            if(!(root->left) && !(root->right))
            {
                string str;
                for(auto it = path.begin(); it != path.end(); it++)
                {
                    str.append(to_string(*it));
                    str.append("->");
                }
                str = str.substr(0, str.size() - 2);
                stringPath.push_back(str);
            }
            recursiveHelper(root->left, path, stringPath);
            recursiveHelper(root->right, path, stringPath);
            path.pop_back();
        }
};*/

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->right = new TreeNode(5);

    Solution solObj;
    vector<string> finalAnswer = solObj.binaryTreePaths(node);
    for(auto it = finalAnswer.begin(); it != finalAnswer.end(); it++)
        cout<<*it<<" ";
    return 0;
}