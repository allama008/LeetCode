/*
14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            string firstString = strs.front();
            string retString = firstString;           
            for(auto i = strs.begin() + 1; i!= strs.end(); i++)
            {    
                string otherStr = *i;
                cout<<otherStr<<endl;
                int maxLength = max(otherStr.length(), firstString.length());
                for(int j = 0; j < maxLength; j++)
                    if(firstString[j] != otherStr[j])
                    {
                        retString = firstString.substr(0, j);
                        firstString = retString;
                        break;
                    }
            }
            return retString;
        }
};

int main()
{
    Solution solObj;
    vector<string> vec = {"flower", "flow", "flight"};
    string answer = solObj.longestCommonPrefix(vec);
    cout<<answer<<endl;
    /*for(auto i = vec.begin(): vec.end())
    {
        string answer = solObj.longestCommonPrefix(vec[i]);
        cout<<answer<<endl;
    }*/
    return 0;
}