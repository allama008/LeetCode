/*
997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution 
{
    public:
        int findJudge(int n, vector<vector<int>>& trust) 
        {
            vector<int> trustJudge(n+1, 0);
            for(auto it : trust)
            {
                trustJudge[it[0]]--;
                trustJudge[it[1]]++;
            }
            for(int i = 1; i <= n; i++)
                if(trustJudge[i] == n-1)
                    return i;
            return -1;
        }
};

int main()
{
    Solution solObj;
    vector<vector<int>> vec = {{1, 3}, {2, 3}, {3, 1}};
    int finalAnswer = solObj.findJudge(2, vec);
    cout<<finalAnswer<<endl;
    return 0;
}