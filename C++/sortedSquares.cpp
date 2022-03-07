/*
977. Squares of a Sorted Array
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        vector<int> sortedSquares(vector<int>& nums) 
        {
            transform(nums.begin(), nums.end(), nums.begin(), [](int i){return i * i;});
            sort(nums.begin(), nums.end());
            return nums;
            /*for(auto &x : nums)
                x *= x;
            sort(nums.begin(), nums.end());
            return nums;*/
        }
};

int main()
{
    Solution solObj;
    vector<int> vec1 = {-4,-1,0,3,10}, vec2 = {-7,-3,2,3,11};
    vector<int> finalAnswer = solObj.sortedSquares(vec1);
    for(auto x : finalAnswer)
        cout<<x<<" ";
    cout<<endl;
    finalAnswer = solObj.sortedSquares(vec2);
    for(auto x : finalAnswer)
        cout<<x<<" ";
    return 0;
}