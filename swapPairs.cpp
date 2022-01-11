/*
24. Swap Nodes in Pairs
https://leetcode.com/problems/swap-nodes-in-pairs/
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
        ListNode* swapPairs(ListNode* head) 
        {
            if(head == NULL)
                return NULL;
            else if(head != NULL and head->next == NULL)
                return head;
            else
            {
                ListNode *firstNode = head->next;
                ListNode *temp = (head->next)->next;
                head->next->next = head;
                head->next = swapPairs(temp);
                return firstNode;
            }
        }
};
int main()
{
    vector<int> vec = {1};
    ListNode *temp1 = NULL, *temp2 = NULL;
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        if(temp2 != NULL)
            temp1 = new ListNode(*i, temp2);
        else
            temp1 = new ListNode(*i);
        temp2 = temp1;
    }
    ListNode *printNode = temp1, *firstNode = temp1;
    while (printNode != NULL) 
    {
        cout << printNode->val << " ";
        printNode = printNode->next;
    }
    cout<<endl;
    Solution solObj;
    ListNode* answer = solObj.swapPairs(firstNode);
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}