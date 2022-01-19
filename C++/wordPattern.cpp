/*
290. Word Pattern
https://leetcode.com/problems/word-pattern/
*/

#include<iostream>
#include<string.h>
#include<sstream>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution 
{
    public:
        bool wordPattern(string pattern, string s) 
        {
            stringstream ss(s), ss1(s);
            string tempStr, tempStr1;
            unordered_map<char, string> umap;
            unordered_map<string, char> umap1;
            unordered_map<char, string>::iterator it;
            unordered_map<string, char>::iterator it1;
            unordered_map<char, string> *endPointer;
            unordered_map<string, char> *endPointer1;
            stack<string> emptyChecker;
            int i = 0, strLen = pattern.length();

            while(getline(ss1, tempStr1, ' '))
                emptyChecker.push(tempStr1);
            while(getline(ss, tempStr, ' ') && i < strLen)
            {
                cout<<tempStr<<" ";
                it = umap.find(pattern[i]);
                it1 = umap1.find(tempStr);
                if(it == umap.end() && it1 == umap1.end())
                {
                    umap[pattern[i]] = tempStr;
                    umap1[tempStr] = pattern[i];
                }
                else if(it != umap.end() && it->second != tempStr)
                    return false;
                else if(it1 != umap1.end() && it1->second != pattern[i])
                    return false;
                i++;
                emptyChecker.pop();
            }
            if((!emptyChecker.empty() && i == strLen) || (emptyChecker.empty() && i != strLen))
                return false;
            return true;
        }
};

int main()
{
    string pattern = "abbaa", s = "dog cat cat dog";
    Solution solObj;
    bool finalAnswer = solObj.wordPattern(pattern, s);
    cout<<boolalpha<<finalAnswer<<endl;
    return 0;
}