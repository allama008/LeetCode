/*
219. Contains Duplicate II
https://leetcode.com/problems/contains-duplicate-ii/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) 
        {
            unordered_map<int, int> umap;
            int vectorSize = nums.size();
            for(int i = 0; i < vectorSize; i++)
            {
                if(umap.find(nums[i]) != umap.end() && i - umap[nums[i]] <= k)
                    return true;
                else
                    umap[nums[i]] = i;
                return false;        
            }
        }
};

