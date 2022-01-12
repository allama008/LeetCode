/*
2. Add Two Numbers
https://leetcode.com/problems/add-two-numbers/submissions/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<iostream>
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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode *add = NULL, *firstNode = NULL;
            int carry = 0;
            while(l1 != NULL || l2 != NULL)
            {
                int sum = 0;
                if(l1 == NULL)
                {
                    sum = l2->val + carry;
                    carry = 0;
                    if(sum>=10)
                    {
                        sum= sum%10;
                        carry = 1;
                    }
                    ListNode *node = new ListNode(sum);
                    add->next = node;
                    add = node;
                    l2 = l2->next;
                }
                else if (l2 == NULL)
                {
                    sum = l1->val + carry;
                    carry = 0;
                    if(sum>=10)
                    {
                        sum= sum%10;
                        carry = 1;
                    }
                    ListNode *node = new ListNode(sum);
                    add->next = node;
                    add = node;
                    l1 = l1->next;
                }
                else
                {
                    sum = l1->val + l2->val + carry;
                    carry = 0;
                    if(sum>=10)
                    {
                        sum= sum%10;
                        carry = 1;
                    }   
                    ListNode *node = new ListNode(sum);
                    if(add!=NULL)
                        add->next = node;
                    else
                        firstNode = node;
                    add = node;
                    l1 = l1->next;
                    l2 = l2->next;
                }
            } 
            if(carry == 1)
            {
                ListNode *node = new ListNode(1);
                add->next = node;
                add = node;
            }
            return firstNode;
        }
};*/

// LEETCODE SOLUTION. ALMOST SAME LOGIC BUT ELEGANT CODE.
/*class Solution 
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode *dummyHead = new ListNode(0);
            ListNode *p = l1, *q = l2, *curr = dummyHead;
            int carry = 0;
            while (p != NULL || q != NULL) 
            {
                int x = (p != NULL) ? p->val : 0;
                int y = (q != NULL) ? q->val : 0;
                int sum = carry + x + y;
                carry = sum / 10;
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
                if (p != NULL) p = p->next;
                if (q != NULL) q = q->next;
            }
            if (carry > 0)
                curr->next = new ListNode(carry);
            return dummyHead->next;
        }
};*/

// SECOND SOLUTION USING RECURSION ^_^
class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
        {
            ListNode *finalAnswer = addTwoNumbersHelper(l1, l2, 0);
            return finalAnswer;
        }
        ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry)
        {
            if(l1 == NULL && l2 == NULL && carry == 0)
                return NULL;
            else if(l1 == NULL && l2 == NULL && carry == 1)
                return new ListNode(carry);
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            ListNode *curr = new ListNode(sum%10);
            curr->next = addTwoNumbersHelper((l1 != NULL) ? l1->next : NULL, (l2 != NULL) ? l2->next : NULL, carry);
            return curr;
        }
};

int main()
{

    int arr1[] = {9, 9, 9, 9, 9, 9, 9};
    int arr2[] = {9, 9, 9, 9};
    /*int arr1[] = {3, 4, 2};
    int arr2[] = {4, 6, 5};*/
    ListNode *temp2 = NULL, *temp1 = NULL;
    for(int i = 0; i < 7; i++)
    {
        if(temp2!=NULL)
            temp1 = new ListNode(arr1[i], temp2);
        else
            temp1 = new ListNode(arr1[i]);
        temp2 = temp1;
    }
    ListNode *firstNode = temp1;
    ListNode *answer = firstNode;
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;
    temp1, temp2 = NULL;
    for(int i = 0; i < 4; i++)
    {
        if(temp2!=NULL)
            temp1 = new ListNode(arr2[i], temp2);
        else
            temp1 = new ListNode(arr2[i]);
        temp2 = temp1;
    }
    ListNode * secondNode = temp1;
    answer = secondNode;
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
    cout<<endl;

    // ListNode *firstTrois = new ListNode(3);
    // ListNode *firstDeux = new ListNode(4, firstTrois);
    // ListNode *firstUno = new ListNode(2, firstDeux);
    // answer = firstUno;
    // while (answer != NULL) 
    // {
    //     cout << answer->val << " ";
    //     answer = answer->next;
    // }
    // ListNode *secondTrois = new ListNode(4);
    // ListNode *secondDeux = new ListNode(6, secondTrois);
    // ListNode *secondUno = new ListNode(5, secondDeux);
    Solution solObj;
    answer = solObj.addTwoNumbers(firstNode, secondNode);
    while (answer != NULL) 
    {
        cout << answer->val << " ";
        answer = answer->next;
    }
}
