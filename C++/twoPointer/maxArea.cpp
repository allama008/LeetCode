/*
11. Container With Most Water
https://leetcode.com/problems/container-with-most-water/
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
    public:
        int maxArea(vector<int>& height) 
        {
            vector<int>::iterator forwardIt = height.begin();
            vector<int>::iterator reverseIt = height.end()-1;
            int maxArea = INT_MIN;
            while(forwardIt < reverseIt)
            {
                maxArea = max(maxArea, min(*forwardIt, *reverseIt) * int(distance(forwardIt, reverseIt)));
                if(*forwardIt > *reverseIt)
                    reverseIt--;
                else
                    forwardIt++;
            }
            return maxArea;
        }
};


int main()
{
    vector<int> inputVector = {3, 2, 1, 3}; //{1,8,6,2,5,4,8,3,7}; //{1,3,2,5,25,24,5};
    Solution solObj;
    cout<<solObj.maxArea(inputVector)<<endl;
    return 0;
}


/*
class Solution
{
    public:
        int maxArea(vector<int>& height) 
        {
            int startIdx = 0, endIdx = height.size()-1;
            int maxArea = INT_MIN;
            if(height.size() == 2)
                return min(height[startIdx], height[endIdx]);
            while(startIdx < endIdx)
            {
                maxArea = max(maxArea, min(height[startIdx], height[endIdx]) * int(distance(height.at(startIdx), height + endIdx)));
                if(height[startIdx] < height[startIdx+1])
                    startIdx++;
                else if(height[endIdx] < height[endIdx-1])
                    endIdx--;
                else if(height[startIdx] > height[endIdx])
                    endIdx--;
                else if(height[endIdx] > height[startIdx])
                    startIdx++;
                else if(height[startIdx+1] > height[endIdx-1])
                    startIdx++;
                else
                    endIdx--;
            }
            return maxArea;
        }
};
*/