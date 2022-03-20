/*
1007. Minimum Domino Rotations For Equal Row
https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
        {
            vector<int> topVector(7, 0), bottomVector(7, 0), sameVector(7, 0);
            int vectorLength = tops.size();
            for(int i = 0; i < vectorLength; i++)
            {
                topVector[tops[i]]++;
                bottomVector[bottoms[i]]++;
                if(tops[i] == bottoms[i])
                    sameVector[tops[i]]++;
            }
            for(int i = 0; i < 7; i++)
                if(topVector[i] + bottomVector[i] - sameVector[i] == vectorLength)
                    return vectorLength - max(topVector[i], bottomVector[i]);
            return -1;
        }
};

int main()
{
    vector<int> tops = {2,1,2,4,2,2}, bottoms = {5,2,6,2,3,2}, tops1 = {3,5,1,2,3}, bottoms1 = {3,6,3,3,4};
    Solution solObj;
    cout<<solObj.minDominoRotations(tops, bottoms)<<solObj.minDominoRotations(tops1, bottoms1)<<endl;
    return 0;
}