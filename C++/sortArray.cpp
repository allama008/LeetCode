/*
912. Sort an Array
https://leetcode.com/problems/sort-an-array/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        vector<int> sortArray(vector<int>& nums) 
        {
            sort(nums.begin(), nums.end());
            return nums;
        }
};

int main()
{
    vector<vector<int>> vec = {{5,2,3,1}, {5,1,1,2,0,0}};
    vector<int> finalAnswer;
    Solution solObj;
    for(int i = 0; i < vec.size(); i++)
    {
        finalAnswer = solObj.sortArray(vec[i]);
        for(auto it = finalAnswer.begin(); it != finalAnswer.end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
}