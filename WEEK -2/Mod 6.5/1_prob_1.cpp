#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> adj[N];

bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(visited[v] == false)
        {
            dfs(v);
        }
    }
    cout<<"visiting "<<u<<endl;
}

int main()
{
    int n, m ;
    cin>>n>>m;

    for(int i =1; i<= m; i++)
    {
        int u, v;
        cin>> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i = 1; i<=n;i++)
    {
        cout<<"adj["<<i<<"] : ";
        for(int v : adj[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }

    dfs(1);

    return 0;
}