#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int n, m;
vector<pair<pair<int, int>, int>> listOfEdges;
int dist[101];

void FordBellman(int src)
{
    for (int i = 0; i <= 101; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto el : listOfEdges)
        {
            int u = el.first.first;
            int v = el.first.second;
            int w = el.second;

            if(dist[u] != INF and dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w; 
            }
        }
    }
}

int main()
{
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        listOfEdges.push_back({{u, v}, w});
    }

    // for(auto el: listOfEdges)
    // {
    //     cout<<el.first.first<<" to "<<el.first.second<<" : "<<el.second<<endl;
    // }

    FordBellman(1);

    for(int i = 1; i<=n; i++)
    {
        if(dist[i] == INF)
        {
            cout<<"30000"<<" "; 
        }
        else
        cout<<dist[i]<<" "; 
    }

    return 0;
}