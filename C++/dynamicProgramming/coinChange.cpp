/*
322. Coin Change
https://leetcode.com/problems/coin-change/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Wrong implementation.
class Solution 
{
    public:
        int coinChange(vector<int>& coins, int amount) 
        {
            sort(coins.begin(), coins.end());
            int coinCount = 0;
            for(auto it = coins.rbegin(); it != coins.rend(); it++)
            {
                while(amount >= *it && amount != 0)
                {
                    amount -= *it;
                    coinCount++;
                }
            }
            if(amount)
                return -1;
            return coinCount;
        }
};

int main()
{
    vector<int> denominations = {1};
    Solution solObj;
    int finalAnswer = solObj.coinChange(denominations, 0);
    cout<<finalAnswer<<endl;
    return 0;
}