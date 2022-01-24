/*
102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

#include<iostream>
#include<vector>
#include<queue>
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


//My solution. Wrong because it assumes a complete binary tree
/*class Solution 
{
    public:
        vector<vector<int>> levelOrder(TreeNode* root) 
        {   
            vector<vector<int>> levelorderList;
            vector<int> tempList;
            if(!root)
                return levelorderList;
            queue<TreeNode*> q;
            TreeNode *temp;
            int i = 0, j = 0, f;
            q.push(root);

            while(!q.empty())
            {
                temp = q.front();
                f = temp->val;
                //cout<<f<<" ";
                q.pop();
                //cout<<"Checkpoint0.\n";
                tempList.push_back(f);
                if(i == pow(2, j) || i == 0)
                {
                    //levelorderList.resize(j+1);
                    levelorderList.push_back(tempList);
                    //levelorderList[j].push_back(f);
                    tempList = {};
                    j++;
                }
                //cout<<"Checkpoint1.\n";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                //cout<<"Checkpoint2.\n";
                i++;          
            }
            if(!tempList.empty()) levelorderList.push_back(tempList);
            //cout<<"Checkpoint1\n";
            return levelorderList;
        }
};*/

/*class Solution
{
    public:
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
            vector<vector<int>> levelorderList;
            vector<int> tempList;
            if(!root)
                return levelorderList;
            queue<TreeNode*> q;
            TreeNode *temp;

            q.push(root);
            q.push(NULL);
            while(!q.empty())
            {
                temp = q.front();
                q.pop();
                if(!temp)
                {
                    levelorderList.push_back(tempList);
                    tempList.clear();
                    if(!q.empty())
                        q.push(NULL);
                    continue;
                }
                tempList.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            return levelorderList;
        }
};*/

class Solution
{
    public:
        vector<vector<int>> vec;
        void recursiveHelper(TreeNode* node, int depth)
        {
            if(node == NULL)
                return;
            if(vec.size() == depth)
                vec.resize(depth+1);
            
            vec[depth].push_back(node->val);
            recursiveHelper(node->left, depth + 1);
            recursiveHelper(node->right, depth + 1);
        }
        vector<vector<int>> levelOrder(TreeNode* root) 
        {
            recursiveHelper(root, 0);
            return vec;
        }
};

int main()
{
    /*TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);*/
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);

    Solution solObj;
    vector<vector<int>> vec = solObj.levelOrder(node);
    cout<<"Checkpoint2\n";
    for(int i = 0; i < vec.size(); i++)
    {   
        cout<<"[";
        for(auto it = vec[i].begin(); it != vec[i].end(); it++)
            cout<<*it<<" ";
        cout<<"]"<<endl;
    }
}