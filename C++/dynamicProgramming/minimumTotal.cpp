/*
120. Triangle
https://leetcode.com/problems/triangle/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Didn't read the question properly. Wrong solution
/*class Solution 
{
    public:
        int minimumTotal(vector<vector<int>>& triangle) 
        {
            int sum = 0;
            for(int i = 0; i < triangle.size(); i++)
                sum += *min_element(triangle[i].begin(), triangle[i].end());
            return sum;
        }
};*/

class Solution 
{
    public:
        int minimumTotal(vector<vector<int>>& triangle) 
        {
            int vectorSize = triangle.size();
            for(int i = 1; i < vectorSize; i++)
                triangle[i][0] += triangle[i-1][0];
            for(int i = 1; i < vectorSize; i++)
                for(int j = 1; j <= i; j++)
                    if(i == j)
                        triangle[i][j] += triangle[i-1][j-1];
                    else
                        triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            return *min_element(triangle[vectorSize-1].begin(), triangle[vectorSize-1].end());
        }
};

int main()
{
    vector<vector<int>> vec1 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, vec2 = {{-10}}, vec3 = {{-1}, {2, 3}, {1, -1, -3}};
    Solution solObj;
    cout<<solObj.minimumTotal(vec1)<<" "<<solObj.minimumTotal(vec2)<<" "<<solObj.minimumTotal(vec3)<<endl;
    return 0;
}

