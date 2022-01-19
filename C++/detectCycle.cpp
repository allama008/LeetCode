/*
142. Linked List Cycle II
https://leetcode.com/problems/linked-list-cycle-ii/
*/

/*
Logic behind this is as follows:
x1: Distance between head point and entry point
x2: Distance between entry point and meeting point
x3: Distance between meeting point and entry point

Therefore
Slow pointer distance traveled = x1 + x2
Fast pointer distance traveled = x1 + x2 + x3 + x2
Relationship between the two:
2(x1 + x2) = x1 + x2 + x3 + x2 {Since fast pointer travels two times as much as slow pointer}
x1 = x3
*/



struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
    public:
        ListNode *detectCycle(ListNode *head) 
        {
            ListNode *slow = head;
            ListNo
        }
};