/*
100. Same Tree
https://leetcode.com/problems/same-tree/
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

//INCORRECT
/*class Solution 
{
    public:
        bool tempAnswer;
        bool isSameTree(TreeNode* p, TreeNode* q) 
        {   
            cout<<p->val<<" "<<q->val<<endl;
            if(!p && !q)
                return false;
            if(p->val != q->val)
                return false;
            if((p->left != NULL && q->left == NULL) || (p->left == NULL && q->left != NULL)) 
                return false;
            if((p->right != NULL && q->right == NULL) || (p->right == NULL && q->right != NULL))
                return false;
            if(p->left != NULL && q->left != NULL)
            {    
                tempAnswer = isSameTree(p->left, q->left);
                if(!tempAnswer) return false;
            }   
            if(p->right != NULL && q->right != NULL) 
            {    
                tempAnswer = isSameTree(p->right, q->right);
                if(!tempAnswer) return false;
            }
            return true;
        }
};*/

class Solution 
{
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) 
        {
            if(!q && !q)
                return true;
            if((p == NULL && q != NULL) || (p != NULL && q == NULL))
                return false;
            if(p->val != q->val)
                return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
};

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(1);

    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(1);
    node1->right = new TreeNode(2);

    Solution solObj;
    bool finalAnswer = solObj.isSameTree(node, node1);
    cout<<boolalpha<<finalAnswer<<endl;
    return 0;
}
