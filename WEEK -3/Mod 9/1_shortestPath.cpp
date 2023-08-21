#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+8;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q; 
    q.push(src);
    visited[src] = true;
    level[src]=0;
    parent[src] = -1;

    while(!q.empty())
    {
        int u  = q.front();
        q.pop();

        for(int v: adj[u])
        {
            if(visited[v] == false)
            {
                q.push(v);
                visited[v]= true;
                level[v] = level[u]+1; 
                parent[v] = u; 
            }
        }
    }
}

int main()
{
    int n, m ; cin >> n >> m; 

    for(int i =1; i<=m; i++)
    {
        int u, v ; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(int v: adj[i])
    //     {
    //         cout<<v<<" ";
    //     }
    //     cout<<endl; 
    // }

    int s, d; 
    cin >> s >> d; 

    bfs(s);
    cout<<level[d]<<endl;

    for(int i =1; i<=n; i++)
    {
        cout<<"Parent of "<<i<<": "<<parent[i]<<endl;
    }

    vector<int> path;
    int current = d;
    // while(parent[current] != -1)
    while(current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    // path.push_back(current);

    reverse(path.begin(),path.end());
    for(int el : path)
    {
        cout<<el<<" ";
    }
    cout<<endl; 
    

    return 0;
}