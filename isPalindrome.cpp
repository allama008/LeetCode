/*
9. Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isPalindrome(int x) 
        {
            if(x < 0)
                return false;
            string str = to_string(x);
            int N = str.length();
            for(int i = 0, j = N-1; i < j; i++, j--)
                if(str[i] != str[j])
                    return false;
            return true;


        }
};

int main()
{
    Solution solObj;
    vector<int> vec = {-121, 121, 1001, 1234, 3324, 12321, 123321};
    for(auto i = vec.begin(); i != vec.end(); i++)
    {
        bool answer = solObj.isPalindrome(*i);
        cout<<answer<<endl;
    }
    return 0;
}