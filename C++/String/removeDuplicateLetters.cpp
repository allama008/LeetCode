/*
316. Remove Duplicate Letters
https://leetcode.com/problems/remove-duplicate-letters/
*/

// Same as question --> 1081. Smallest Subsequence of Distinct Characters
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        string removeDuplicateLetters(string s) 
        {
            int strLength = s.length();
            stack<int> subseqStack;
            unordered_map<char, int> charCount;
            unordered_map<char, bool> charMarking;
            string result = "";

            for(auto c : s)
                charCount[c]++;

            for(auto it = charCount.begin(); it != charCount.end(); it++)
                charMarking[it->first] = false;
            
            for(int i = 0; i < strLength; i++)
            {
                charCount[s[i]]--;
                if(charMarking[s[i]])
                    continue;
                
                while(!subseqStack.empty() && s[i] < s[subseqStack.top()] && charCount[s[subseqStack.top()]] > 0)
                {
                    charMarking[s[subseqStack.top()]] = false;
                    subseqStack.pop();
                }

                subseqStack.push(i);
                charMarking[s[i]] = true;
            }

            while(!subseqStack.empty())
            {
                result = s[subseqStack.top()] + result;
                subseqStack.pop();
            }
            return result;
        }
};