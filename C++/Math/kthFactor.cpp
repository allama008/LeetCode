/*
1492. The kth Factor of n
https://leetcode.com/problems/the-kth-factor-of-n/
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) 
    {
        vector<int> smallFactors, bigFactors;
        for(int i = 1; i <= sqrt(n); i++)
            if(n%i == 0)
            {
                smallFactors.push_back(i);
                if(i != n/i)
                    bigFactors.push_back(n/i);
            }
        smallFactors.insert(smallFactors.end(), bigFactors.rbegin(), bigFactors.rend());

        if(k > smallFactors.size())
            return -1;
        return smallFactors[k-1];
    }
};

int main()
{
    Solution solObj;
    cout<<solObj.kthFactor(5, 2)<<endl;
    return 0;
}
