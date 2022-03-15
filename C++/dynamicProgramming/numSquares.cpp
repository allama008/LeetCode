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
        int numSquares(int n) 
        {
            vector<int> numSquaresContainer(n + 1, INT_MAX);
            numSquaresContainer[0] = 0;
            for(int i = 1; i <= n; i++)
                for(int j = 1; j*j <= i; j++)
                    numSquaresContainer[i] = min(numSquaresContainer[i], numSquaresContainer[i - j*j] + 1);
            return numSquaresContainer.back();
        }
};

int main()
{
    Solution solObj;
    cout<<solObj.numSquares(12)<<" "<<solObj.numSquares(13)<<endl;
    return 0;
}
