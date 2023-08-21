#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> adj[N];

bool visited[N] ;
int depth[N];
int height[N];

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

    for(int v : adj[u])
    {
        if(visited[v] == false)
        {
            depth[v] = depth[u]+1;
            dfs(v);
            if(height[v] + 1 > height[u])
            {
                height[u] = height[v]+1;
            }
        }
        
    }
}




int main()
{
    int n, m ; 
    cin >>n >>m ; 
    for(int i =1; i<=m ; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printAdjacency(n);

    cout<<endl<<endl;

    dfs(1);
    for(int i = 1; i<= n; i++)
    {
        cout<<"Depth of "<<i<<": "<<depth[i]<<endl;
    }   

    cout<<endl<<endl;

    for(int i = 1; i<= n; i++)
    {
        cout<<"Height of "<<i<<": "<<height[i]<<endl;
    }  

    return 0;
}