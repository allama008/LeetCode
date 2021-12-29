/*
50. Pow(x, n)
https://leetcode.com/problems/powx-n/
*/

#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double temp;
        if(n==0)
            return 1;
        if(n>=0)    
            temp = myPow(x, n/2);
        else
            temp = myPow(1/x, n/2);
        if(n%2==0)
            return temp*temp;
        else
            return x*temp*temp;
    }
};

int main()
{
    Solution solObj;
    double answer = solObj.myPow(2, -2);
    cout<<answer<<endl;
    return 0;
}