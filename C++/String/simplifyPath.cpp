/*
221. Maximal Square
https://leetcode.com/problems/maximal-square/
*/

#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
#include <sstream>
using namespace std;

class Solution {
    public:
        string simplifyPath(string path) 
        {
            string result, temp;
            vector<string> stk;
            stringstream ss(path);
            while(getline(ss, temp, '/')) 
            {
                if (temp == "" or temp == ".") 
                    continue;
                /*if (temp == ".." and !stk.empty())
                    stk.pop_back();
                else if (temp != "..") 
                    stk.push_back(temp);*/
                if (temp != "..") 
                    stk.push_back(temp);
                else if (!stk.empty()) 
                    stk.pop_back();
            }
            for(auto str : stk) 
                result += "/" + str;
            return result.empty() ? "/" : result;
        }
};

int main()
{
    string str = "/home/", str1 = "/../", str2 = "/home//foo/";
    Solution solObj;
    cout<<solObj.simplifyPath(str)<<" "<<solObj.simplifyPath(str1)<<" "<<solObj.simplifyPath(str2)<<endl;
    return 0;
}