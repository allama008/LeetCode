/*
520. Detect Capital
https://leetcode.com/problems/detect-capital/
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool detectCapitalUse(string word) 
        {   
            bool firstLetter;
            bool isCapital = false, isNotCapital = false;
            if(word.length() == 1)
                return true;
            if(isupper(word[0]))
                firstLetter = true;
            else
                firstLetter = false;
            for(int i = 1; i < word.length(); i++)
            {
                if(firstLetter)
                {
                    if(isupper(word[i]))
                        isCapital = true;
                    else
                        isNotCapital = true;
                    if(isCapital && isNotCapital)
                        return false;
                }
                else
                    if(isupper(word[i]))
                        return false;
            }
            return true;
        }
};

int main()
{
    vector<string> checkVector = {"USA", "leetcode", "Google", "FlaG", "FLAg", "FLaG", "flAg"};
    Solution solObj;
    for(int i = 0; i < checkVector.size(); i++)
    {
        cout<<checkVector[i]<<" ";
        cout<<boolalpha<<solObj.detectCapitalUse(checkVector[i])<<endl;
    }
    return 0;
}