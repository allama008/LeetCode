/*
1. Two Sum
https://leetcode.com/problems/two-sum/
*/

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> vec;
            for(auto i = nums.begin(); i != nums.end(); i++)
                for(auto j = i + 1; j != nums.end(); j++)
                    if(*i + (*j) == target)
                    {
                        auto it = vec.insert(vec.begin(), int(j - nums.begin()));
                        vec.insert(it, int(i - nums.begin()));
                    }
            return vec;           
            
        }
};

int main()
{
    Solution solobj;
    //solobj.printHello();
    vector<int> Sol = {2, 7, 11, 15};
    Sol = solobj.twoSum(Sol, 9);
    for(auto i = Sol.begin(); i != Sol.end(); i++)
        cout<<*i<<" ";
    return 0;
}