/*
19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

/*
class Solution 
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            ListNode *fast = head, *slow = head;
            for (int i = 0; i < n; i++) 
                fast = fast->next;
            if (!fast) 
                return head->next;
            while (fast->next)
            {
                fast = fast->next
                slow = slow->next;
            }
            slow->next = slow->next->next;
            return head;
        }
};
*/

//My Solution. Works faster than the above internet solution but the logic of above is good.

class Solution 
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            vector<ListNode*> vectorList;
            ListNode *traversal = head;
            while(traversal)
            {
                vectorList.push_back(traversal);
                traversal = traversal->next;
            }
            int vectorSize = vectorList.size();
            int deleteIndex = vectorSize - n;
            if(deleteIndex == 0)
                return head->next;
            else if(deleteIndex == vectorSize - 1)
                vectorList[deleteIndex-1]->next = NULL;
            else
                vectorList[deleteIndex-1]->next = vectorList[deleteIndex]->next;
            return head;
        }
};

//First implementation by me which did not work.
/*
class Solution 
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) 
        {
            ListNode *fastPointer = head, *slowPointer = head, *deletePointer = head;
            while(slowPointer && fastPointer)
            {
                for(int i = 0; i < n && fastPointer; i++)
                    fastPointer = fastPointer->next;
                if(n == 1 && !slowPointer->next)
                    break;
                slowPointer = slowPointer->next;
            }
            if(deletePointer == slowPointer)
                return NULL;
            while(deletePointer && deletePointer->next != slowPointer)
                deletePointer = deletePointer->next;
            deletePointer->next = slowPointer->next;
            return head;
        }
};
*/


int main()
{
    vector<int> vec1 = {2, 1};
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

    Solution solObj;
    ListNode *finalAnswer = solObj.removeNthFromEnd(firstNode1, 2);
    answer = finalAnswer;
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}