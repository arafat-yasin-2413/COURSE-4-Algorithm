#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;
vector<int> adj[N];
bool visited[N];

// int parent[N];

bool dfs(int u, int parent)
{
    bool isCycle = false;
    visited[u] = true;

    for(int v : adj[u])
    {
        if(v != parent)
        {
            if(visited[v] == true) 
            return true;
            isCycle |= dfs(v,u);
        }
        
        
    }
    return isCycle;
}



int main()
{
    int n, m;
    cin >> n >> m;

    for(int i =1;i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 

    }

    for(int i =1; i<=n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int v: adj[i] )
        {
            cout<<v <<" ";
        }
        cout<<endl;
    }

    // if(dfs(1,-1))
    // {
    //     cout<<"Cycle Detected"<<endl;
    // }
    // else 
    // {
    //     cout<<"No Cycle"<<endl;
    // }

    bool isCycle= false;
    for(int i = 1; i<=n; i++)
    {
        if(visited[i]== false)
        {
            isCycle |= dfs(i,-1);
        }  
    }

    if(isCycle)
    {
        cout<<"Cycle Detected"<<endl;
    }

    else 
        cout<<"No Cycle"<<endl; 

   
    
    

    return 0;
}