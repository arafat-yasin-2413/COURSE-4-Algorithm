#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    // cout<<src<<" ";
    level[src] =0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" "; 

        for(int v : adj[u])
        {
            if(visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                // cout<<v<<" ";
                level[v] = level[u]+1;
            }
        }
    }
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

    cout<<endl<<"BFS Traversal: "<<endl;
    bfs(1);
    cout<<endl<<endl;

    for(int i = 1; i<=n;i++)
    {
        cout<<"level of "<<i<<" : "<<level[i]<<endl;
    }
    

    return 0;
}