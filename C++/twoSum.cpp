/*
1. Two Sum
https://leetcode.com/problems/two-sum/
*/

#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> vec;
            unordered_map<int, int> umap;
            int diff;
            for(int i = 0; i < nums.size(); i++)
            {
                diff = target - nums[i];
                if(umap.find(diff) != umap.end())
                {
                    vec.push_back(i);
                    vec.push_back(umap.find(diff)->second);
                    return vec;
                }
                umap[nums[i]] = i;
            }
            return vec;
        }
        
        //Below solution is fast, but not that fast
        /*vector<int> twoSum(vector<int>& nums, int target) 
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
        }*/

        //Below solution is slower. Try using iterators.
        /*vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> vec;
            for(auto i = 0; i < nums.size(); i++)
                for(auto j = i + 1; j < nums.size(); j++)
                    if(nums[i] + nums[j] == target)
                    {
                        vec.push_back(i);
                        vec.push_back(j);
                    }
            return vec;             
        }*/
};

int main()
{
    Solution solobj;
    //solobj.printHello();
    vector<int> Sol = {3, 2, 4};
    Sol = solobj.twoSum(Sol, 6);
    for(auto i = Sol.begin(); i != Sol.end(); i++)
        cout<<*i<<" ";
    return 0;
}