/*
413. Arithmetic Slices
https://leetcode.com/problems/arithmetic-slices/
*/

#include<iostream>
#include<vector>
using namespace std;

//Same implementation as the solution below but with iterators;
class Solution 
{
    public:
        int numberOfArithmeticSlices(vector<int>& nums) 
        {
            if(nums.size() < 3)
                return 0;
            int result = 0, count = 0;
            for(auto it = nums.begin() + 2; it != nums.end(); it++)
            {
                if(*it - *(it - 1) == *(it-1) - *(it-2))
                    count++;
                else
                    count = 0;
                result += count;
            }
            return result;
        }
};
/*
class Solution 
{
    public:
        int numberOfArithmeticSlices(vector<int>& nums) 
        {
            if(nums.size() < 3)
                return 0;
            int result = 0, count = 0;
            for(int i = 2; i < nums.size(); i++)
            {
                if(nums[i] - nums[i - 1] == nums[i-1] - nums[i-2])
                    count++;
                else
                    count = 0;
                result += count;
            }
            return result;
        }
};
*/
int main()
{
    vector<int> vector1 = {1, 2, 3, 4}, vector2 = {1};
    Solution solObj;
    int finalAnswer = solObj.numberOfArithmeticSlices(vector1);
    cout<<finalAnswer<<endl;
    finalAnswer = solObj.numberOfArithmeticSlices(vector2);
    cout<<finalAnswer<<endl;
    return 0;
}