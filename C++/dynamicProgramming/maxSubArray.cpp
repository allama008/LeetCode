/*
53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Dynamic Programming Approach. O(n)
class Solution 
{
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int maxSoFar = *nums.begin(), currMax = *nums.begin();
            for(auto it = nums.begin() + 1; it != nums.end(); it++)
            {
                currMax = max(*it, currMax + *it);
                maxSoFar = max(maxSoFar, currMax);
            }
            return maxSoFar;
        }
};
//Another O(n) approach
/*
class Solution 
{
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int maxSoFar = INT_MIN, maxEndingHere = 0;
            for(auto it = nums.begin(); it != nums.end(); it++)
            {
                if(*it <= maxEndingHere + *it)
                    maxEndingHere += *it;
                else
                    maxEndingHere = *it;
                if(maxEndingHere > maxSoFar)
                    maxSoFar = maxEndingHere;
            }
            return maxSoFar;
        }
};
*/
//O(n) approach. This approach is more simple and intuitive for 0(n)
/*
class Solution 
{
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int maxSoFar = INT_MIN, maxEndingHere = 0;
            for(auto it = nums.begin(); it != nums.end(); it++)
            {
                maxEndingHere += *it;
                if(maxSoFar < maxEndingHere)
                    maxSoFar = maxEndingHere;
                if(maxEndingHere < 0)
                    maxEndingHere = 0;
            }
            return maxSoFar;
        }
};
*/
int main()
{
    vector<int> inputVector = {5, 4, -1, 7, 8}, inputVector1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4}, inputVector2 = {1};
    Solution solObj;
    cout<<solObj.maxSubArray(inputVector)<<endl;
    cout<<solObj.maxSubArray(inputVector1)<<endl;
    cout<<solObj.maxSubArray(inputVector2)<<endl;
    return 0;
}