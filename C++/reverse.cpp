/*
7. Reverse Integer
https://leetcode.com/problems/reverse-integer/
*/

#include<iostream>
using namespace std;

class Solution 
{
    public:
        int reverse(int x) 
        {
            long long int m = 0;
            while(n)
            {
                int d = n % 10;
                m = 10 * m + d;
                if(m > INT_MAX || m < INT_MIN)
                    return 0;
                n /= 10;
            }
            return m;
        }
};