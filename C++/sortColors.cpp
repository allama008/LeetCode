/*
75. Sort Colors
https://leetcode.com/problems/sort-colors/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        void sortColors(vector<int>& nums) 
        {
            int countZero = 0, countOne = 0, countTwo = 0;
            for(auto x : nums)
                if(x == 0)
                    countZero++;
                else if(x == 1)
                    countOne++;
                else
                    countTwo++;
            for(auto it = nums.begin(); it < nums.begin() + countZero; it++)
                *it = 0;
            for(auto it = nums.begin() + countZero; it < nums.begin() + countZero + countOne; it++)
                *it = 1;
            for(auto it = nums.begin() + countZero + countOne; it != nums.end(); it++)
                *it = 2;
        }
};

int main()
{
    Solution solObj;
    vector<int> vec1 = {2, 0, 2, 1, 1, 0}, vec2 = {2, 0, 1};
    solObj.sortColors(vec1);
    for(auto x : vec1)
        cout<<x<<" ";
    cout<<endl;
    solObj.sortColors(vec2);
    for(auto x : vec2)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}