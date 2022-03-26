/*
704. Binary Search
https://leetcode.com/problems/binary-search/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


class Solution 
{   
    private:
        int helperFunction(int lb, int ub, vector<int> &nums, int target)
        {
            int mid = (ub + lb)/2;
            if(ub == lb && target != nums[mid])
                return -1;
            if(target > nums[mid])
            {
                lb = mid + 1;
                return helperFunction(lb, ub, nums, target);
            }
            else if(target < nums[mid])
            {
                ub = mid - 1;
                return helperFunction(lb, ub, nums, target);
            }
            else if(target == nums[mid])
                return mid;
            return -1;
        }

    public:
        int search(vector<int>& nums, int target) 
        {
            return helperFunction(0, nums.size() - 1, nums, target);
        }
};

int main()
{
    vector<int> arr = {-1, 0, 3, 5, 9, 12, 22};
    Solution solObj;
    cout<<solObj.search(arr, 9)<<" "<<solObj.search(arr, 2)<<endl;
    return 0;
}