/*
740. Delete and Earn
https://leetcode.com/problems/delete-and-earn/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int deleteAndEarn(vector<int>& nums) 
        {
            vector<int> freq(100001, 0);
            int maxNum = *max_element(nums.begin(), nums.end());
            for(auto numsElement : nums)
                freq[numsElement] += numsElement;
            int currPoints = freq[1], prevPoints = 0;
            for(int i = 2; i <= maxNum; i++)
            {
                int temp = currPoints;
                currPoints = max(currPoints, prevPoints + freq[i]);
                prevPoints = temp;
            }
            return currPoints;
            
        }
};

int main()
{
    vector<int> vec1 = {3, 4, 2}, vec2 = {2, 2, 3, 3, 3, 4};
    Solution solObj;
    cout<<solObj.deleteAndEarn(vec1)<<endl;
    cout<<solObj.deleteAndEarn(vec2)<<endl;
    return 0;
}