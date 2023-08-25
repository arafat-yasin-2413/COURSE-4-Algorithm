#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
vector<int> adj[N];
bool visited [N];
vector<int> level(N);

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<" "; 
        q.pop();

        for(int v : adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
            level[v] =  level[u]+1; 
        }
    }
}

int main()
{
    int n, m ; 
    cin >> n >> m; 
    for(int i = 1; i<=m; i++)
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
    
    bfs(1);

    // for(int i = 0; i<14; i++)
    // {
    //     cout<<level[i]<<endl;
    // }

    
    cout<<endl;
    for(int i = 1; i<=n; i++)
    {
        cout<<"Level of "<<i<<": "<<level[i]<<endl; 
    }
    return 0;
}














/*
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> adj[N];
bool visited[N];
int level[N];


void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<"Visiting "<<u<<endl;

        for(int v : adj[u])
        {
            if(visited[v] == false)
            {
                level[v] = level[u]+1;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

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

int main()
{
    int n , m ; 
    cin >> n >> m ;

    for(int i = 1 ; i<=m; i++)
    {
        int u , v ; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    printAdjacency(n);
    cout<<endl;

    bfs(1);

    cout<<endl<<endl;
    for(int i = 1; i<=n; i++)
    {
        cout<<"Level of "<<i<<" : "<<level[i]<<endl;
    }


    

    return 0;
}
*/








