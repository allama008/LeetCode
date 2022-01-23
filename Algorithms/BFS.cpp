/*
BFS Implementation Practice
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> edgeList;
vector<bool> visited;

void addEdge(int u, int v)
{
    edgeList[u].push_back(v);
    //edgeList[v].push_back(u) // Add in case of undirected graph
}

void BFS(int u)
{
    queue<int> q;

    visited[u] = true;
    q.push(u);

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        
        cout<<f<<" ";

        for(auto i = edgeList[f].begin(); i != edgeList[f].end(); i++)
            if(!visited[*i])
            {
                visited[*i] = true;
                q.push(*i);
            }
    }
}

int main()
{
    int n, e, u, v;
    cin >> n >> e;

    visited.assign(n, false);
    edgeList.assign(n, vector<int>());

    for(int i = 0; i < e; i++)
    {
        cin>>u>>v;
        addEdge(u, v);
    }

    for(int j = 0; j < n; j++)
        if(!visited[j])
            BFS(j);
    return 0;
}