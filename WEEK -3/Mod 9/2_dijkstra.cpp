#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+8;
const int INF = 1e9+9;
vector<pair<int,int>> adj[N];
vector<int> dist(N,INF);
vector<bool> visited(N);

void dijkstra(int src)
{
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    dist[src] = 0;
    pq.push({dist[src],src});


    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u]= true;

        for(pair<int,int> pr : adj[u])
        {
            int v = pr.first;
            int w = pr.second;

            if(visited[v]) continue;

            // relaxation
            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    int n, m ; 
    cin >> n >> m ; 

    for(int i = 1; i<=n; i++)
    {
        int u, v, w ; 
        cin >> u >> v >> w; 
        adj[u].push_back({v,w});
    }

    for(int i = 1; i<=n; i++)
    {
        cout<<"List "<<i<<": ";
        for(pair<int,int> pr : adj[i])
        {
            cout<<"("<<pr.first<<","<<pr.second<<")"<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    dijkstra(1);
    for(int i = 1; i<= n; i++)
    {
        cout<<"Distance of "<<i<<": "<<dist[i]<<endl;
    }

    // print visited array
    cout<<endl;
    for(int i =1 ; i<=n; i++)
    {
        cout<<"Visiting node "<<i<<": "<<visited[i]<<endl;
    }

    return 0;
}






























/*
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pr;
const int N = 1e3+5;
const int INF = 1e9+10;

// vector<pair<int,int>> adj[N];
vector<pr> adj[N];
vector<int> dist(N,INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue < pr,vector<pr>,greater<pr> > pq;

    dist[source] = 0;
    pq.push({dist[source],source});


    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(pr vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second; 

            if(visited[v]) continue;

            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v}); 
            }
        }
    }
}


/*
7 8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12
*/
/*
int main()
{
    int n, m ; 
    cin >> n >> m; 

    for(int i =1;i<=m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});

    }

    dijkstra(1);

    for(int i = 1; i<=n; i++)
    {
        cout<<"Distance of "<<i<<": "<<dist[i]<<endl;

    }


    return 0;
}
*/