#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
vector<int> adj[N];
bool visited [N];

void dfs(int u )
{
    visited[u] = true;
    cout<<u<<" ";
    for(int v : adj[u])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}

int main()
{
    int n, m  ;
    cin >> n >> m ;
    for(int i = 1;i<=m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(int v : adj[i])
    //     {
    //         cout<<v<<" ";
    //     }
    //     cout<<endl; 
    // }

    dfs(1);

    return 0;
}







































/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> adj[N];
bool visited[N];


void printAdjacency(int n)
{
    for(int i = 1; i<=n; i++)
    {
        cout<<"List "<<i<<": ";
        for(int v : adj[i])
        {
            cout<<v <<" ";
        }
        cout<<endl;
    }
}

void dfs(int u)
{
    visited[u] = true;
    cout<<u<<" ";
    for(int v : adj[u])
    {
        if(visited[v] == false)
        {
            dfs(v);
        }
        
    }
}

int main()
{
    int n, m ; 
    cin >> n >> m;

    for(int i =1; i<=m ; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  


    printAdjacency(n);
    cout<<endl;
    cout<<"DFS Traversal : "<<endl;
    dfs(1);
    

    return 0;
}
*/