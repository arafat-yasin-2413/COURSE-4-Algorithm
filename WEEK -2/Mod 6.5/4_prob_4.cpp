#include<bits/stdc++.h>
using namespace std;

const int N= 1e6+8;
vector<int>adj[N];
bool visited[N];
int depth[N];

void dfs(int u)
{
    visited[u] = true;
    for(int v : adj[u])
    {
        if(visited[v] == false)
        {
            depth[v] = depth[u]+1;
            dfs(v);
        }
    }
    
}

int main()
{
    int n, m; 
    cin >>n >>m; 

    for(int i = 1; i<=m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x;cin>>x;

    dfs(1);
    // for(int i =1 ; i<=n; i++)
    // {
    //     cout<<depth[i]<<" ";
    // }
    // cout<<endl; 

    cout<<"Depth of "<<x<<" = "<<depth[x]<<endl;
    return 0;
}