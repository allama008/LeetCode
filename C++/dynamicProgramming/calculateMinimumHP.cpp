/*
174. Dungeon Game
https://leetcode.com/problems/dungeon-game/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution 
{
    public:
        int calculateMinimumHP(vector<vector<int>>& dungeon) 
        {
            int vectorSize = dungeon.size(), columnSize = dungeon[0].size();
            vector<vector<int>> minHealthCost(vectorSize + 1, vector<int>(columnSize + 1, INT_MAX));
            minHealthCost[vectorSize][columnSize - 1] = 1; minHealthCost[vectorSize - 1][columnSize] = 1;
            for(int i = vectorSize - 1; i >= 0; i--)
                for(int j = columnSize - 1; j >= 0; j--)
                {
                    int need = min(minHealthCost[i + 1][j], minHealthCost[i][j + 1]) - dungeon[i][j];
                    minHealthCost[i][j] = need <= 0 ? 1 : need;
                }
            return minHealthCost[0][0];
        }
};

//Approach is wrong. You cannot go from top-left to bottom-right because
//the minimum health depends on future values of the demon.
//You need to iterate from the bottom-right to top-left
/*
class Solution 
{
    public:
        int calculateMinimumHP(vector<vector<int>>& dungeon) 
        {
            int vectorSize = dungeon.size(), columnSize = dungeon[0].size(), minimum = INT_MAX;
            vector<vector<pair<int, int>>> minHealthCost(vectorSize, vector<pair<int, int>>(columnSize));
            minHealthCost[0][0].first = dungeon[0][0]; minHealthCost[0][0].second = dungeon[0][0];
            for(int j = 1; j < columnSize; j++)
            {
                minHealthCost[0][j].first = dungeon[0][j] + minHealthCost[0][j-1].first;
                minHealthCost[0][j].second = min(minHealthCost[0][j].first, minHealthCost[0][j-1].second);
            }
            for(int i = 1; i < vectorSize; i++)
            {
                minHealthCost[i][0].first = dungeon[i][0] + minHealthCost[i-1][0].first;
                minHealthCost[i][0].second = min(minHealthCost[i][0].first, minHealthCost[i-1][0].second);
            }
            for(int i = 1; i < vectorSize; i++)
                for(int j = 1; j < columnSize; j++)
                    if(minHealthCost[i-1][j].second > minHealthCost[i][j-1].second)
                    {
                        minHealthCost[i][j].first = dungeon[i][j] + minHealthCost[i-1][j].first;
                        minHealthCost[i][j].second = min(minHealthCost[i][j].first, minHealthCost[i-1][j].second);
                    }
                    else if(minHealthCost[i-1][j].second < minHealthCost[i][j-1].second)
                    {
                        minHealthCost[i][j].first = dungeon[i][j] + minHealthCost[i][j-1].first;
                        minHealthCost[i][j].second = min(minHealthCost[i][j].first, minHealthCost[i][j-1].second);
                    }
                    else 
                        if(minHealthCost[i-1][j].first > minHealthCost[i][j-1].first)
                        {
                            minHealthCost[i][j].first = dungeon[i][j] + minHealthCost[i-1][j].first;
                            minHealthCost[i][j].second = min(minHealthCost[i][j].first, minHealthCost[i-1][j].second);
                        }
                        else
                        {
                            minHealthCost[i][j].first = dungeon[i][j] + minHealthCost[i][j-1].first;
                            minHealthCost[i][j].second = min(minHealthCost[i][j].first, minHealthCost[i][j-1].second);
                        }
            return minHealthCost[vectorSize-1][columnSize-1].second <= 0 ? abs(minHealthCost[vectorSize-1][columnSize-1].second) + 1 : 1;
        }
};
*/

//Solution using absolute value. How close the health is to 0 marker.
//Wrong solution completely based on example test-case
//Fails to take into account that no health is required if the path
//is filled with magic orbs. 
/*class Solution 
{
    public:
        int calculateMinimumHP(vector<vector<int>>& dungeon) 
        {
            int vectorSize = dungeon.size(), columnSize = dungeon[0].size(), minimum = INT_MAX;
            for(int i = 1; i < vectorSize; i++)
                dungeon[i][0] += dungeon[i-1][0];
            for(int i = 1; i < columnSize; i++)
                dungeon[0][i] += dungeon[0][i-1];
            for(int i = 1; i < vectorSize; i++)
                for(int j = 1; j < columnSize; j++)
                    if(abs(dungeon[i][j] + dungeon[i][j-1]) < abs(dungeon[i][j] + dungeon[i-1][j]))
                        dungeon[i][j] += dungeon[i][j-1];
                    else
                        dungeon[i][j] += dungeon[i-1][j];
            // for(int x : dungeon[vectorSize-1])
            //     if(abs(x) < minimum)
            //         minimum = x <= 0 ? abs(x) + 1 : x;
            // return minimum;
            return (dungeon[vectorSize-1][columnSize-1] <= 0 ? abs(dungeon[vectorSize-1][columnSize-1]) + 1 : dungeon[vectorSize-1][columnSize-1]);
        }
};*/

int main()
{
    //vector<vector<int>> vec1 = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}}, vec2 = {{0}};
    //vector<vector<int>> vec1 = {{-2, -3, 3}, {-5, 1, 1}, {10, 30, -5}};
    vector<vector<int>> vec1 = {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    Solution solObj;
    cout<<solObj.calculateMinimumHP(vec1)<<endl;
    //cout<<solObj.calculateMinimumHP(vec1)<<" "<<solObj.calculateMinimumHP(vec2)<<endl;
    return 0;
}