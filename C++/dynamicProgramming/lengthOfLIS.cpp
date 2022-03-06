/*
300. Longest Increasing Subsequence
https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int lengthOfLIS(vector<int>& nums) 
        {
            int numsLength = nums.size();
            vector<int> lis(numsLength, 1);
            for(int i = 1; i < numsLength; i++)
                for(int j = 0; j < i; j++)
                    if(nums[i] > nums[j] && lis[i] < lis[j] + 1) //if lis[i] = lis[j] + 1 then no use of repeating the operation. if lis[i] > lis[j] + 1 then there exists an increasing subsequence already.
                        lis[i] = lis[j] + 1;
            return *max_element(lis.begin(), lis.end());
        }
};

int main()
{
    vector<int> vec1 = {10,9,2,5,3,7,101,18}, vec2 = {0,1,0,3,2,3}, vec3 = {7,7,7,7,7,7,7};
    Solution solObj;
    cout<<solObj.lengthOfLIS(vec1)<<" "<<solObj.lengthOfLIS(vec2)<<" "<<solObj.lengthOfLIS(vec3)<<endl;
    return 0;
}