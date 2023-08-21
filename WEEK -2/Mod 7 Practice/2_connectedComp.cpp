#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> adj[N];
bool visited[N];
vector<int> comp[N];

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

void dfs(int u,int cnt)
{
    visited[u] = true;
    comp[cnt].push_back(u);
    for(int v: adj[u])
    {
        if(visited[v] == false)
        {
            dfs(v,cnt);
        }
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

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
    int n, m ;
    cin>> n >> m;
    for(int i =1; i<=m ; i++)
    {
        int u , v;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printAdjacency(adj,n); 

    cout<<endl;

    int cc = 0;
    for(int i =1; i<=n; i++)
    {
        if(visited[i] == false)
        {
            cc++;
            dfs(i,cc);
            // bfs(i);
        }
    }   

    cout<<"Number of Connected Components : "<<endl<<cc<<endl;

    cout<<endl;
    printAdjacency(comp,cc);
    

    return 0;
}