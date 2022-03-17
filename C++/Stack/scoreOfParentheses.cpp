/*
856. Score of Parentheses
https://leetcode.com/problems/score-of-parentheses/
*/

#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution 
{
    public:
        int scoreOfParentheses(string s) 
        {
            int counter = -1, score = 0;
            int stringLength = s.length();
            stack<char> balParenStack;
            for(int i = 0; i < stringLength; i++)
                if(s[i] == '(')
                    counter++;
                else if(s[i] == ')' && counter > -1)
                {
                    score += pow(2, counter);
                    while(s[i] == ')')
                    {
                        counter--;
                        i++;
                    }
                    i--;
                }
            return score;
        }
};
/*
class Solution 
{
    public:
        int scoreOfParentheses(string s) 
        {
            int counter = -1, score = 0;
            int stringLength = s.length();
            stack<char> balParenStack;
            for(int i = 0; i < stringLength; i++)
            {
                if(s[i] == '(')
                    counter++;
                else if(s[i] == ')' && !counter)
                {
                    score += 1;
                    counter--;
                }
                else if(s[i] == ')' && counter > 0)
                {
                    score += 2 * counter;
                    counter = -1;
                }
                else if(s[i] == ')' && counter == -1)
                    continue;
            }
            return score;
        }
};
*/
int main()
{
    string str = "()", str1 = "(()(()))", str2 = "()()";
    Solution solObj;
    cout<<solObj.scoreOfParentheses(str)<<" "<<solObj.scoreOfParentheses(str1)<<" "<<solObj.scoreOfParentheses(str2)<<endl;
    return 0;
}