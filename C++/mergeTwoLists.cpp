/*
21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists/
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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
        {
            if(list1 == NULL && list2 == NULL)
                return NULL;
            else if(list1 == NULL)
            {
                ListNode *curr = new ListNode(list2->val);
                curr->next = mergeTwoLists(NULL, list2->next);
                return curr;
            }
            else if(list2 == NULL)
            {
                ListNode *curr = new ListNode(list1->val);
                curr->next = mergeTwoLists(list1->next, NULL);
                return curr;
            }
            else
            {
                ListNode *curr = new ListNode((list1->val <= list2->val) ? list1->val : list2->val);
                curr->next = mergeTwoLists((list1->val <= list2->val) ? list1->next : list1, (list1->val <= list2->val) ? list2 : list2->next);
                return curr;
            }
            

            /*int x = (list1 != NULL) ? list1->val : 300;
            int y = (list2 != NULL) ? list2->val : 300;
            ListNode* curr = (x <= y) ? list1 : list2;
            curr->next = mergeTwoLists((x <= y) ? list1->next : list1, (x <= y) ? list2 : list2->next);
            return curr;*/


            


        }
};
int main()
{
    vector<int> vec1 = {4, 2, 1};
    vector<int> vec2 = {0};

    ListNode *temp1 = NULL, *temp2 = NULL;
    for(auto i = vec1.begin(); i != vec1.end(); i++)
    {
        if(temp2 != NULL)
            temp1 = new ListNode(*i, temp2);
        else
            temp1 = new ListNode(*i);
        temp2 = temp1;
    }
    ListNode *firstNode1 = temp1, *answer = temp1;
    /*while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;*/

    temp1 = NULL, temp2 = NULL;
    for(auto i = vec2.begin(); i != vec2.end(); i++)
    {
        if(temp2 != NULL)
            temp1 = new ListNode(*i, temp2);
        else
            temp1 = new ListNode(*i);
        temp2 = temp1;
    }
    ListNode *secondNode = temp1;
    answer = secondNode;
    /*while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;*/

    Solution solObj;
    ListNode *finalAnswer = solObj.mergeTwoLists(/*firstNode1*/NULL, secondNode);
    while (finalAnswer != NULL) 
    {
        cout << finalAnswer->val << " ";
        finalAnswer = finalAnswer->next;
    }
    return 0;
}