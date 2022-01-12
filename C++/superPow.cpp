/*
372. Pow(x, n)
https://leetcode.com/problems/super-pow/
NOT SOLVED. ERROR BECAUSE pow(a, sum) IS TOO
LARGE A VALUE TO BE CONTAINED AS AN INT
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
    public:
        int superPow(int a, vector<int>& b) 
        {
            int sum = 0, k = 0;
            for(auto it = b.rbegin(); it != b.rend(); it++, k++)
                sum += *it * pow(10, k);
            return int(pow(a, sum))%1337;
        }
};
int main()
{
    Solution solObj;
    vector<int> vec = {1, 1};
    double answer = solObj.superPow(2, vec);
    cout<<answer<<endl;
    return 0;
}