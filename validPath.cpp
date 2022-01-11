/*
1971. Find if Path Exists in Graph
https://leetcode.com/problems/find-if-path-exists-in-graph/
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution 
{
    public:
        bool validPath(int n, vector<vector<int>>& edges, int start, int end) 
        {
            vector<int> adjList[n];
            int k = edges.size();
            for(int i = 0; i < k; i++)
            {
                adjList[edges[i][0]].push_back(edges[i][1]);
                adjList[edges[i][1]].push_back(edges[i][0]);
            }
            for(auto it = adjList[start].begin(); it != adjList[start].end(); it++)
                if(*it == end)
                    return true;

            vector<bool> visited(n, false);
            queue<int> q;
            int frontNode;

            q.push(start);
            visited[start] = true;            

            while(!q.empty())
            {
                frontNode = q.front();
                q.pop();
                for(auto i = adjList[frontNode].begin(); i != adjList[frontNode].end(); i++)
                    if(*i == end)
                        return true;
                    else if(!visited[*i])
                    {
                        visited[*i] = true;
                        q.push(*i);
                    }
            }
            return false;
        }
};

int main()
{
    Solution solObj;
    vector<vector<int>> vec = {{0,1},{1,2},{2,0}};
    bool finalAnswer = solObj.validPath(3, vec, 0, 2);
    cout<<boolalpha<<finalAnswer<<endl;
    return 0;
}