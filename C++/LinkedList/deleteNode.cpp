/*
237. Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/
*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
    public:
        void deleteNode(ListNode* node) 
        {
            node->val = node->next->val;
            node->next = node->next->next;
        }
};