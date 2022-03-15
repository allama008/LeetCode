/*
322. Coin Change
https://leetcode.com/problems/coin-change/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int coinChange(vector<int>& coins, int amount) 
        {
            if(amount == 0)
                return 0;
            sort(coins.begin(), coins.end());
            vector<int> coinsState(amount + 1, INT_MAX);
            coinsState[0] = 0;
            for(int i = 1; i <= amount; i++)
                for(int j = 0; j < coins.size(); j++)
                    if(i - coins[j] < 0)
                        break;
                    else if(coinsState[i - coins[j]] != INT_MAX)
                        coinsState[i] = min(coinsState[i], coinsState[i - coins[j]] + 1);
            if(coinsState.back() == INT_MAX)
                return -1;
            else
                return coinsState.back();
        }
};

//Wrong implementation.
// [186,419,83,408] --> [83, 186, 408, 419]
// Amount = 6249
/*
class Solution 
{
    public:
        int coinChange(vector<int>& coins, int amount) 
        {
            if(!amount)
                return 0;
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
};*/

int main()
{
    vector<int> denominations = {1};
    Solution solObj;
    int finalAnswer = solObj.coinChange(denominations, 0);
    cout<<finalAnswer<<endl;
    return 0;
}