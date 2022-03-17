/*
221. Maximal Square
https://leetcode.com/problems/maximal-square/
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution 
{
    public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
        {
            int i = 0;
            stack<int> stacked;
            for(int x : pushed)
            {
                stacked.push(x);
                while(!stacked.empty() && stacked.top() == popped[i])
                {
                    stacked.pop();
                    i++;
                }
            }
            return stacked.empty();
        }
};
int main()
{
    vector<int> pushed {1,2,3,4,5}, popped = {4,5,3,2,1};
    Solution solObj;
    cout<<boolalpha<<solObj.validateStackSequences(pushed, popped)<<endl;
    return 0;
}