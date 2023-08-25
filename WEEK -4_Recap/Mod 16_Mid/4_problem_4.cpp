#include<bits/stdc++.h>
using namespace std;

const int N =1e+5;
const int INF = 1e9+7;
vector<pair<int,int>> adj[N];
vector<int> dist(N,INF);
bool visited[N];


void dijkstra(int src)
{
    priority_queue< pair<int,int>, vector< pair<int,int>>, greater<pair<int,int> >> pq;
    dist[src] = 0;
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

            if(visited[v]) continue;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w; 
                pq.push({dist[v],v});
            }
        }
    }
}

int main()
{
    int n, m ; 
    cin >> n >> m ;

    while(m--)
    {
        int u, v, w; 
        cin >> u >> v >> w; 
        adj[u].push_back({v,w});

    } 

    // for(int i = 1; i<=n;i++)
    // {
    //     for(auto v : adj[i])
    //     {
    //         cout<< "("<< v.first <<","<<v.second <<")" <<" ";
    //     }
    //     cout<<endl;
    // }
    
    int src;
    cin >> src; 
    dijkstra(src);

    // for(int i=1; i<=n;i++)
    // {
    //     cout<<"Dist of "<<i <<": " <<dist[i]<<endl;
    // }

    int test;
    cin >> test;
    while(test--)
    {
        long long int dest, dw;
        cin >> dest >> dw;

        if(dist[dest] <= dw)
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }

    return 0;
}