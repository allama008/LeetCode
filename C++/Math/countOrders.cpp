/*
1359. Count All Valid Pickup and Delivery Options
https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        int countOrders(int n) 
        {
            int sum = 1, count = 1, mod = 1e9+7;
            long long result = 1;
            for(int i = 0; i < n; i++)
            {
                result = result * sum % mod;
                sum += ++count;
                sum += ++count;
            }
            return result%mod;
        }
};

int main()
{
    Solution solObj;
    cout<<solObj.countOrders(1)<<" "<<solObj.countOrders(2)<<" "<<solObj.countOrders(3)<<" "<<solObj.countOrders(4)<<endl;
    return 0;
}