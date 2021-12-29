/*
20. Valid Parentheses
https://leetcode.com/problems/valid-parentheses/
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution 
{
    public:
        bool isValid(string s) 
        {
            stack<char> parenthesisStack;
            int length = s.length();
            for(int i = 0; i < length; i++)
                if (s[i] != ']' && s[i] != '}' && s[i] != ')')
                    parenthesisStack.push(s[i]);
                else if (!parenthesisStack.empty())
                    if (s[i] == ']' && parenthesisStack.top() == '[')
                        parenthesisStack.pop();
                    else if (s[i] == '}' && parenthesisStack.top() == '{')
                        parenthesisStack.pop();
                    else if (s[i] == ')' && parenthesisStack.top() == '(')
                        parenthesisStack.pop();
                    else
                        return false;
                else 
                    return false;
            if (!parenthesisStack.empty())
                return false;
            return true;
        }
};

int main()
{
    Solution solObj;
    bool answer = solObj.isValid("]");
    cout<<boolalpha<<answer<<endl;
    return 0;
}