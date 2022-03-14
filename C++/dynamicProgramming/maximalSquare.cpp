/*
221. Maximal Square
https://leetcode.com/problems/maximal-square/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int maximalSquare(vector<vector<char>>& matrix) 
        {
            int rowSize = matrix.size(), columnSize = matrix[0].size(), width = 0, maxVal = 0;
            vector<vector<int>> state(rowSize, vector<int>(columnSize, 0));
            for(int i = 0; i < rowSize; i++)
            {
                state[i][0] = matrix[i][0] - '0';
                maxVal = max(maxVal, state[i][0]);
            }
            for(int i = 1; i < columnSize; i++)
            {
                state[0][i] = matrix[0][i] - '0';
                maxVal = max(maxVal, state[0][i]);
            }
            for(int i = 1; i < rowSize; i++)
                for(int j = 1; j < columnSize; j++)
                    if(matrix[i][j] == '1')
                    {
                        state[i][j] = min({state[i-1][j], state[i][j-1], state[i-1][j-1]}) + 1;
                        maxVal = max(maxVal, state[i][j]);
                    }
                    else
                        state[i][j] = 0;
            return maxVal * maxVal;
        }
};

int main()
{
    //vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
    Solution solObj;
    cout<<solObj.maximalSquare(matrix)<<endl;
    return 0;
}