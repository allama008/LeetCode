/*
701. Insert into a Binary Search Tree
https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Solution 
{
    public:
        vector<string> summaryRanges(vector<int>& nums) 
        {
            queue<int> q;
            string str;
            vector<string> stringVector;
            if(nums.empty())
                return stringVector;
            for(auto it = nums.begin(); it != nums.end(); it++)
            {
                if(q.empty())
                    q.push(*it);
                else if(*it == *(it-1) + 1)
                    q.push(*it);
                else
                {
                    while(!q.empty())
                    {
                        if(q.front() == q.back())
                            str = to_string(q.front());
                        else
                           str = str + to_string(q.front()) + "->" + to_string(q.back());
                        q = queue<int>();
                    }
                    stringVector.push_back(str);
                    str = "";
                    q.push(*it);
                }
            }
            while(!q.empty())
            {
                if(q.front() == q.back())
                    str = to_string(q.front());
                else
                    str = str + to_string(q.front()) + "->" + to_string(q.back());
                q = queue<int>();
            }
            stringVector.push_back(str);
            return stringVector;
        }
};

int main()
{
    vector<int> inputVector = {0,1,2,4,5,7};//{0,2,3,4,6,8,9};
    Solution solObj;
    vector<string> finalAnswer = solObj.summaryRanges(inputVector);
    for(auto strIdx : finalAnswer)
        cout<<strIdx<<" ";
    cout<<endl;
    return 0;
}