/*
88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
        {
            nums1.resize(m);
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
            sort(nums1.begin(), nums1.end());       
        }
};

int main()
{
    Solution solObj;
    vector<int> vec1 = {0}, vec2 = {1};
    int m = 0, n = 1;
    solObj.merge(vec1, m, vec2, n);
    for(auto x : vec1)
        cout<<x<<" ";
    return 0;
}