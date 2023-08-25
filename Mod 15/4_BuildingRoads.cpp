#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int> adj[N]; 
bool visited[N];


void dfs(int src)
{
    visited[src] = true; 
    for(int v : adj[src])
    {
        if(visited[v]) continue;
        dfs(v);     
    }
}

int main()
{
    int n, m ; 
    cin >> n >> m ; 

    for(int i = 1; i<=m; i++)
    {
        int u , v ; 
        cin >> u >> v ; 
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }


    int cnt = 0; 
    vector<int> roads;
    for(int i = 1 ; i<=n; i++)
    {
        if(!visited[i])
        {
            // cnt++;
            roads.push_back(i); 
            dfs(i); 
        }
    }

    // cout<<cnt-1<<endl; 
    cout<<roads.size()-1<<endl; 
    for(int i = 0; i<roads.size()-1; i++)
    {
        cout<<roads[i]<<" "<<roads[i+1]<<endl;
    }

    return 0;
}