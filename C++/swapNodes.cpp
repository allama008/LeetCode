/*
1721. Swapping Nodes in a Linked List
https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
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

/*class Solution 
{
    public:
        ListNode* swapNodes(ListNode* head, int k) 
        {
            vector<int> vec;
            ListNode *temp = head;
            int tempVar;
            while(temp != NULL)
            {
                vec.push_back(temp->val);
                temp = temp->next;
            }

            //Swap the elements in the vector
            tempVar = vec[k-1];
            vec[k-1] = vec[vec.size() - k];
            vec[vec.size() - k] = tempVar;

            //Start building the ll
            ListNode *temp1 = NULL, *temp2 = NULL;
            for(auto i = vec.rbegin(); i != vec.rend(); i++)
            {
                if(temp2 != NULL)
                    temp1 = new ListNode(*i, temp2);
                else
                    temp1 = new ListNode(*i);
                temp2 = temp1;
            }
            return temp1;
        }
};*/

class Solution 
{
    public:
        ListNode* swapNodes(ListNode* head, int k) 
        {
            ListNode *temp1 = head, *temp2 = head, *temp3 = head;
            for(int i = k-1; i > 0; i--)
                temp3 = temp3->next;
            temp1 = temp3; 
            temp3 = temp3->next;
            while(temp3)
            {
                temp3 = temp3->next;
                temp2 = temp2->next;
            }
            int temp = temp1->val;
            temp1->val = temp2->val;
            temp2->val = temp;
            return head;
        }
};

int main()
{
    vector<int> vec = {7,9,6,6,7,8,3,0,9,5};
    ListNode *temp1 = NULL, *temp2 = NULL;
    for(auto i = vec.rbegin(); i != vec.rend(); i++)
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
    ListNode* answer = solObj.swapNodes(firstNode, 5);
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}