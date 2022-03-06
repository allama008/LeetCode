/*
64. Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Dynamic Programming Solution
class Solution 
{
    public:
        int minPathSum(vector<vector<int>>& grid) 
        {
            int rowSize = grid.size();
            int columnSize = grid[0].size();

            for(int i = 1; i < columnSize; i++)
                grid[0][i] += grid[0][i-1];
            for(int i = 1; i < rowSize; i++)
                grid[i][0] += grid[i-1][0];
            for(int i = 1; i < rowSize; i++)
                for(int j = 1; j < columnSize; j++)
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            return grid[rowSize-1][columnSize-1];
        }
};

int main()
{
    vector<vector<int>> vec1 = {{1,3,1},{1,5,1},{4,2,1}}, vec2 = {{1,2,3},{4,5,6}};
    Solution solObj;
    cout<<solObj.minPathSum(vec1)<<" "<<solObj.minPathSum(vec2)<<endl;
    return 0;
}