/*
61. Rotate List
https://leetcode.com/problems/rotate-list/
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
        ListNode* rotateRight(ListNode* head, int k) 
        {
            if(!head)
                return head;
            vector<ListNode*> listVector;
            ListNode *traversal = head;
            while(traversal)
            {
                listVector.push_back(traversal);
                traversal = traversal->next;
            }
            int vectorSize = listVector.size();
            int lastIndex = vectorSize - 1;
            k = k % vectorSize;
            for(int i = 1; i <= k; i++)
            {
                listVector.insert(listVector.begin(), listVector[lastIndex]);
                listVector.erase(listVector.end()-1);
            }
            ListNode *temp = head;
            if(k != 0)
            {
                temp = NULL;
                for(auto rit = listVector.rbegin(); rit != listVector.rend(); rit++)
                {        
                    (*rit)->next = temp;
                    temp = (*rit);
                }
            }
            return temp;
        }
};
int main()
{
    vector<int> vec1 = {2, 1, 0};
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
    ListNode *finalAnswer = solObj.rotateRight(firstNode1, 4);
    answer = finalAnswer;
    cout<<"Hello";
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}