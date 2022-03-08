/*
4. Median of Two Sorted Arrays
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
            sort(nums1.begin(), nums1.end());
            int arrayLength = nums1.size() - 1;
            if(arrayLength % 2 == 0)
                return (double)nums1[arrayLength/2.0];
            else
                return (nums1[arrayLength/2.0] + nums1[arrayLength/2.0 + 1])/2.0;
        }
};

int main()
{
    Solution solObj;
    vector<int> vec1 = {1, 3}, vec2 = {2};
    vector<int> vec3 = {1, 2}, vec4 = {3, 4};
    cout<<solObj.findMedianSortedArrays(vec1, vec2)<<endl;
    cout<<solObj.findMedianSortedArrays(vec3, vec4)<<endl;
    return 0;
}