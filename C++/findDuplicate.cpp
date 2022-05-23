/*
287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int findDuplicate(vector<int>& nums) 
        {
            unordered_map<int, int> umap;
            for(auto it = nums.begin(); it != nums.end(); it++)
                if(++umap[*it] == 2)
                    return *it;
            return -1;
        }
};