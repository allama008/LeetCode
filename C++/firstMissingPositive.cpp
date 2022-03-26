/*
41. First Missing Positive
https://leetcode.com/problems/first-missing-positive/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int firstMissingPositive(vector<int>& nums) 
        {   
            int minValue = 1;
            unordered_map<int, int> umap;
            for(auto it = nums.begin(); it != nums.end(); it++)
            { 
                if(*it > 0)
                {
                    umap[*it]++;
                    if(*it == minValue)
                    {
                        minValue++;
                        while(umap.find(minValue) != umap.end())
                            minValue++;
                    }
                }
            }
            return minValue;
        }
};

int main()
{
    vector<int> inputVector = {7,8,9,11,12};
    Solution solObj;
    cout<<solObj.firstMissingPositive(inputVector)<<endl;
    return 0;
}