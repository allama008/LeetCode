/*
78. Subsets
https://leetcode.com/problems/subsets/
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> subsets(vector<int>& nums) 
        {
            int n = nums.size();
            int count = pow(2, n);
            vector<vector<int>> outsideVec;
            vector<int> insideVec;
            for(int i = 0; i < count; i++)
            {                
                for(int j = 0; j < n; j++)
                    if((i & (1 << j)) != 0)
                        insideVec.push_back(nums[j]);
                outsideVec.push_back(insideVec);
                insideVec.clear();
            }
            return outsideVec;   
        }
};

int main()
{
    vector<int> subsetVec = {1, 2, 3, 4};
    Solution solObj;
    vector<vector<int>> finalSolution = solObj.subsets(subsetVec);
    for(int i = 0; i < finalSolution.size(); i++)
    {
        for(auto it = finalSolution[i].begin(); it != finalSolution[i].end(); it++)
            cout<<*it<<" ";
        cout<<endl;
    }
    return 0;
}