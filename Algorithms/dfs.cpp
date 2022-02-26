/*
DFS Implementation Practice
*/

#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFSUtil(int u, vector<int> adj[], vector<bool> &visited)
{
    visited[u] = true;
    cout<<u<<" ";
    for(int i = 0; i < adj[u].size(); i++)
        if(!visited[adj[])
            DFSUtil(i, adj[])
}