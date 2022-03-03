/*
143. Reorder List
https://leetcode.com/problems/reorder-list/
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
        void reorderList(ListNode* head) 
        {
            vector<ListNode*> vectorList;
            ListNode *traversal = head;
            while(traversal)
            {
                vectorList.push_back(traversal);
                traversal = traversal->next;
            }
            int idx = 0, jdx = vectorList.size() - 1;
            while(idx < jdx && idx + 1 != jdx)
            {
                vectorList[jdx]->next = vectorList[idx]->next;
                vectorList[idx]->next = vectorList[jdx];
                idx++; jdx--;
            }
            vectorList[jdx]->next = NULL;
        }
};

int main()
{

}