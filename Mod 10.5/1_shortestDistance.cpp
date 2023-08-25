#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
const int INF = 1e9+7;
vector<pair<int,int>> adj[N];
bool visited[N];
vector<int> dist(N,INF);
int parent[N];

void dijkstra(int src)
{
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

    dist[src] = 0; 
    parent[src] = -1; 
    pq.push({dist[src],src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(auto vpair : adj[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if(visited[v] ) continue;
            // relaxation
            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
                parent[v] = u;
            }
        }
    }
}

/*
6
9
1 2 5
2 3 2
1 3 10
3 4 1
4 1 5
1 5 9
5 6 1
2 6 4
2 5 2
4 6
*/

int main()
{
    int n, m ; 
    cin >> n >> m ;

    for(int i = 1; i<=m ;  i++)
    {
        int u, v , w; 
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); 
    }

    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": ";
    //     for(auto ele : adj[i])
    //     {
    //         cout<<"("<<ele.first<<","<<ele.second<<")"<<" ";
    //     }
    //     cout<<endl;
    // }

    int src, dest; 
    cin >> src >>dest;

    dijkstra(src);

    cout<<"dist["<<dest<<"] : "<<dist[dest]<<endl;

     
    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<"Parent of "<<i<<": "<<parent[i]<<endl; 
    // }
    // cout<<endl; 

    int curr = dest;
    vector<int> path;
    while(curr!= - 1) 
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(),path.end());

    cout<<"Shortest Path :"<<endl;
    for(auto el : path)
    {
        cout<<el<<" ";
    }

    



    return 0;
}