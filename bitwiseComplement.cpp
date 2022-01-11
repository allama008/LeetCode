/*
1009. Complement of Base 10 Integer
https://leetcode.com/problems/complement-of-base-10-integer/
*/
#include<iostream>
#include<math.h>
using namespace std;

class Solution 
{
    public:
        int bitwiseComplement(int n) 
        {
            int numberOfBits = floor(log2(n))+1;
            cout<<numberOfBits<<endl;
            cout<<(1 << numberOfBits) - 1<<endl;
            return ((1 << numberOfBits) - 1) ^ n;
        }
};

int main()
{
    Solution solObj;
    int finalAnswer = solObj.bitwiseComplement(10);
    cout<<finalAnswer<<endl;
    return 0;
}