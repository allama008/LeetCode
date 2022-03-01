/*
1305. All Elements in Two Binary Search Trees
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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

//New working solution of 27th February 2022
class Solution 
{
    private:
        void inorderTraversal(TreeNode *root, vector<int> &traversalList)
        {
            if(!root)
                return;
            inorderTraversal(root->left, traversalList);
            traversalList.push_back(root->val);
            inorderTraversal(root->right, traversalList);
        }
    public:
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
        {
            vector<int> traversalList1, traversalList2;
            inorderTraversal(root1, traversalList1);
            inorderTraversal(root2, traversalList2);
            int finalListSize = traversalList1.size() + traversalList2.size();
            vector<int> finalList(finalListSize);
            merge(traversalList1.begin(), traversalList1.end(), traversalList2.begin(), traversalList2.end(), finalList.begin());
            return finalList;
        }
};

//WORKING SOLUTION OF 25th January 2022
/*
class Solution 
{
    private:
        void inorderTraversal(TreeNode *root, vector<int> &traversalList)
        {
            if(!root)
                return;
            inorderTraversal(root->left, traversalList);
            traversalList.push_back(root->val);
            inorderTraversal(root->right, traversalList);
        }
    public:
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
        {
            vector<int> traversalList;
            inorderTraversal(root1, traversalList);
            inorderTraversal(root2, traversalList);
            sort(traversalList.begin(), traversalList.end());
            return traversalList;
        }
};
*/

// IMPLEMENTED MERGE SORT FROM SCRATCH. THE ABOVE SOLUTION SIMPLY REPLACES MERGE SORT
// WITH SORT ALGORITHM FROM STL
/*class Solution 
{
    private:
        void inorderTraversal(TreeNode *root, vector<int> &traversalList)
        {
            if(!root)
                return;
            inorderTraversal(root->left, traversalList);
            traversalList.push_back(root->val);
            inorderTraversal(root->right, traversalList);
        }
        vector<int> mergeSortList(vector<int> firstList, vector<int> secondList)
        {
            int m = firstList.size(), n = secondList.size();
            vector<int>::iterator it = firstList.begin(), it2 = secondList.begin();
            vector<int> mergedList;
            while(it != firstList.end() && it2 != secondList.end())
                if(*it <= *it2)
                {
                    mergedList.push_back(*it);
                    it++;
                }
                else
                {
                    mergedList.push_back(*it2);
                    it2++;
                }
            while(it != firstList.end())
            {
                mergedList.push_back(*it);
                it++;
            }
            while(it2 != secondList.end())
            {
                mergedList.push_back(*it2);
                it2++;
            }
            return mergedList;
        }
    public:
        vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
        {
            vector<int> firstList, secondList, mergedList;
            inorderTraversal(root1, firstList);
            inorderTraversal(root2, secondList);
            mergedList = mergeSortList(firstList, secondList);
            return mergedList;
        }
};*/

int main()
{
    TreeNode *node = new TreeNode(2);
    node->left = new TreeNode(1);
    node->right = new TreeNode(4);

    TreeNode *node1 = new TreeNode(1);
    node1->left = new TreeNode(0);
    node1->right = new TreeNode(3);

    /*TreeNode *node = new TreeNode(1);
    node->right = new TreeNode(8);

    TreeNode *node1 = new TreeNode(8);
    node1->left = new TreeNode(1);*/

    vector<int> finalAnswer;

    Solution solObj;
    finalAnswer = solObj.getAllElements(node, node1);
    for(auto it = finalAnswer.begin(); it != finalAnswer.end(); it++)
        cout<<*it<<" ";
    return 0;
}