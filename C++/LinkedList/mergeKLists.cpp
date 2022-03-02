/*
23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/
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
    private:
        ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            if(!list1)
                return list2;
            if(!list2)
                return list1;
            if(list1->val <= list2->val)
            {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else
            {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            if(lists.empty())
                return nullptr;
            while(lists.size() > 1)
            {
                lists.push_back(mergeTwoLists(lists[0], lists[1]));
                lists.erase(lists.begin());
                lists.erase(lists.begin());
            }
            return lists.front();
        }
};

//Bakwaas solution by me. Wasteful computing.
/*
class Solution 
{   
    private:
        ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            if(!list1 && !list2)
                return NULL;
            else if(!list1)
            {
                ListNode *curr = new ListNode(list2->val);
                curr->next = mergeTwoLists(NULL, list2->next);
                return curr;
            }
            else if(!list2)
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
        }
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            if(lists.size() == 0)
                return NULL;
            vector<ListNode*>::iterator it = lists.begin();
            ListNode *firstList = *it;
            for(it = lists.begin() + 1; it != lists.end(); it++)
            {
                firstList = mergeTwoLists(firstList, *it);
            }
            return firstList;
        }
};
*/

int main()
{
    vector<int> vec1 = {5, 4, 1};
    vector<int> vec2 = {4, 3, 1};
    vector<int> vec3 = {6, 2};

    ListNode *temp1 = NULL, *temp2 = NULL;
    for(auto it = vec1.begin(); it != vec1.end(); it++)
    {
        if(temp2 != NULL)
            temp1 = new ListNode(*it, temp2);
        else
            temp1 = new ListNode(*it);
        temp2 = temp1;
    }
    ListNode *firstNode1 = temp1, *answer = temp1;
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;

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
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;

    temp1 = NULL, temp2 = NULL;
    for(auto i = vec3.begin(); i != vec3.end(); i++)
    {
        if(temp2 != NULL)
            temp1 = new ListNode(*i, temp2);
        else
            temp1 = new ListNode(*i);
        temp2 = temp1;
    }
    ListNode *thirdNode = temp1;
    answer = thirdNode;
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;

    vector<ListNode*> listPointer = {firstNode1, secondNode, thirdNode};
    //vector<ListNode*> listPointer = {firstNode1, secondNode, thirdNode};
    //vector<ListNode*> listPointer = {NULL};
    /* -------------------------------------------------------------------*/

    Solution solObj;
    ListNode *finalAnswer = solObj.mergeKLists(listPointer);
    answer = finalAnswer;
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}