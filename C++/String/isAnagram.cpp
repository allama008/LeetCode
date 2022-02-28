/*
242. Valid Anagram
https://leetcode.com/problems/valid-anagram/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        bool isAnagram(string s, string t) 
        {
            //string firstString = s, secondString = t;
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            if(s == t)
                return true;
            return false;
        }
};

int main()
{
    Solution solObj;
    //cout<<boolalpha<<solObj.isAnagram("anagram", "nagaram");
    cout<<boolalpha<<solObj.isAnagram("a", "b");
    return 0;
}