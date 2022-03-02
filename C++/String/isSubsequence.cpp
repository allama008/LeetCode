/*
392. Is Subsequence
https://leetcode.com/problems/is-subsequence/
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution 
{
    public:
        bool isSubsequence(string s, string t) 
        {
            int sLength = s.size();
            int tLength = t.size();
            int j = 0;
            
            for(int i = 0; i < tLength && j < sLength; i++)
                if(t[i] == s[j])
                    j++;
            
            return j == sLength;
        }
};

int main()
{
    //string s = "abc", t = "ahbgdc";
    string s = "axc", t = "ahbgdc";

    Solution solObj;
    cout<<boolalpha<<solObj.isSubsequence(s, t)<<endl;
    return 0;
}