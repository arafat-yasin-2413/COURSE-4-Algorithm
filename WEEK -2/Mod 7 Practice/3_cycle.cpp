#include<bits/stdc++.h>
using namespace std;

const int N=1e6+6;
vector<int> adj[N];
bool visited[N];


void printAdjacency(vector<int> adjacency[N],int n)
{
    for(int i = 1; i<=n; i++)
    {
        cout<<"List "<<i<<": ";
        for(int v : adjacency[i])
        {
            cout<<v <<" ";
        }
        cout<<endl;
    }
}

bool dfs(int u, int p=-1)
{
    bool cycleExist = false;
    visited[u] = true;

    for(int v : adj[u])
    {
        if(v != p)
        {
            if(visited[v] == true) 
            return true;
            cycleExist |= dfs(v,u);
        }
    }
    return cycleExist;
}

int main()
{
    int n, m;
    cin>> n>>m;

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin >> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printAdjacency(adj,n);
    cout<<endl;


    // if(dfs(1,-1)) 
    //     cout<<"Cycle Detected"<<endl;
    // else 
    //     cout<<"No Cycle"<<endl;

    bool isCycle = false;
    for(int i =1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            isCycle |= dfs(i);
        }
    }

    if(isCycle) 
        cout<<"Cycle Detected"<<endl;
    else 
        cout<<"No Cycle "<<endl;

    return 0;
}