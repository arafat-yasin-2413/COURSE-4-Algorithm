#include<bits/stdc++.h>
using namespace std;

const int N=1e6+7;
vector<int> adj[N];
bool visited[N];

vector<int> comp[N];

void dfs(int u, int cc)
{
    visited[u] = true;
    // cout<<"component "<< cc<<" : "<<u<<endl;
    comp[cc].push_back(u);
    for(int v : adj[u])
    {
        if(visited[v] == false)
        { 
            dfs(v,cc);
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    // cout<<src<<" ";
   

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
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

   
    // bfs(1);
    int cnctCmp = 0;
    
    for(int  i = 1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            cnctCmp++;
            // bfs(i);
            dfs(i,cnctCmp);
            
        }
    }

    cout<<"No. of cnctd Component "<<cnctCmp<<endl;

    for(int i =1; i<=cnctCmp; i++)
    {
        cout<<"Component "<<i<<": ";
        for(int v : comp[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }
    

    return 0;
}