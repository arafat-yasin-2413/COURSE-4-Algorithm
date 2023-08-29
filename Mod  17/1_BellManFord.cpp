#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
const int INF = 1e9+7;
int n, m; 
vector<pair<pair<int,int>,int>> listEdge;
vector<int> dist(N,INF);

void BellmanFord(int src)
{
    dist[src]=0;
    // cout<<dist[0]<<endl;
    // cout<<dist[1]<<endl;
    // cout<<dist[2]<<endl;

    for(int i = 1; i<n ; i++)
    {
        for(auto el : listEdge)
        {
            int u = el.first.first;
            int v = el.first.second;
            int w = el.second;

            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
            }
        }
    }

}

/*
4
4
1 2 5
2 3 2
3 4 -2
1 4 10
1
*/


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
1
*/

int main()
{
    
    cin >> n >> m; 
    for(int i = 1; i<=m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        listEdge.push_back({{u,v},w}); 
    }

    for(auto el : listEdge)
    {
        cout<<el.first.first<<"->"<<el.first.second<< ": "<<el.second<<endl;
    }
    
    int src ; 
    cin >> src; 
    BellmanFord(src);

    cout<<endl; 
    for(int i = 1; i<=n; i++)
    {
        cout<<"D of "<<i<<": "<<dist[i]<<endl;
    }

    return 0;
}













