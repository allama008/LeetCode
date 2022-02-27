/*
653. Two Sum IV - Input is a BST
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/
#include<iostream>
#include<vector>
#include<stack>
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

/*
Time Complexity - O(n) 
Space Complexity - O(n)
*/
/*
class Solution 
{
    private:
        void inorder(TreeNode *root, vector<int> &inorderList)
        {
            if(!root)
                return;
            inorder(root->left, inorderList);
            inorderList.push_back(root->val);
            inorder(root->right, inorderList);
        }
        bool findTargetHelper(TreeNode *root, int target, vector<int> inorderList)
        {
            vector<int>::iterator it, jt;
            //vector<int>::reverse_iterator jt;
            for(it = inorderList.begin(), jt = inorderList.end() - 1; it < jt;)
                if(*it + *jt == target)
                    return true;
                else if(*it + *jt < target)
                    it++;
                else
                    jt--;
            return false;
        }
    public:
        bool findTarget(TreeNode* root, int k) 
        {
            vector<int> inorderList;
            inorder(root, inorderList);
            return findTargetHelper(root, k, inorderList);
        }   
};
*/

/*
Time Complexity - O(n) 
Space Complexity - O(lg n)
*/

class BTSIterator
{
    TreeNode *node;
    stack<TreeNode*> nodeStack;
    bool forward;
    public:
        BTSIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};
        int next()
        {
            while(node || !nodeStack.empty())
                if(node)
                {
                    nodeStack.push(node);
                    node = forward ? node->left : node->right;
                }
                else
                {
                    node = nodeStack.top();
                    nodeStack.pop();
                    int nextValue = node->val;
                    node = forward ? node->right : node->left;
                    return nextValue;
                }
            return -1; //Not required.
        }
};
class Solution 
{
    public:
        bool findTarget(TreeNode* root, int k) 
        {
            if(!root)
                return false;
            BTSIterator left(root, true);
            BTSIterator right(root, false);
            for(int i = left.next(), j = right.next(); i < j;)
                if(i + j == k)
                    return true;
                else if(i + j < k)
                    i = left.next();
                else
                    j = right.next();
            return false;
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

    Solution solObj;
    bool finalAnswer = solObj.findTarget(root, 9);
    cout<<boolalpha<<finalAnswer<<endl;
    return 0;
}
