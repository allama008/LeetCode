/*
799. Champagne Tower
https://leetcode.com/problems/champagne-tower/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        double champagneTower(int poured, int query_row, int query_glass) 
        {
            double result[101][101] = {0.0};
            result[0][0] = poured;
            for (int i = 0; i < query_row + 1; i++)
                for (int j = 0; j <= i; j++) 
                    if (result[i][j] >= 1)
                    {
                        result[i + 1][j] += (result[i][j] - 1) / 2.0;
                        result[i + 1][j + 1] += (result[i][j] - 1) / 2.0;
                        result[i][j] = 1;
                    }
            return result[query_row][query_glass];                                                       
        }
};

int main()
{
    Solution solObj;
    cout<<solObj.champagneTower(1, 1, 1)<<endl;
    cout<<solObj.champagneTower(2, 1, 1)<<endl;
    cout<<solObj.champagneTower(100000009, 33, 17)<<endl;
    return 0;
}