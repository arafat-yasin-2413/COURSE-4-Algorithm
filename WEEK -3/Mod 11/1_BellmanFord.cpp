#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 9;
vector<pair<pair<int, int>, int>> listOfEdges;
const int INF = 1e9+8;
vector<int> dist(N);


void BellmanFord(int src)
{
    for(int i = 1; i<=n; i++)
    {
        dist[i] = INF;
    }
    dist[src] = 0; 

    for(int i = 1; i<m; i++)
    {
        for(auto edge: listOfEdges)
        {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;

            if( dist[u]!=INF and  dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
            }   
        }
    }
}

/*
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3
*/

int main()
{
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        listOfEdges.push_back({{u, v}, w});
    }

    for (auto edg : listOfEdges)
    {
        cout << "(" << edg.first.first << "," << edg.first.second << ")"
             << " -cost-> " << edg.second << " "<<endl;
    }

    cout<<endl<<endl;
    BellmanFord(1);
    for(int i = 1;i<=n;i++)
    {
        cout<<"Dist of node "<<i<<": "<<dist[i]<<endl;
    }



    return 0;
}