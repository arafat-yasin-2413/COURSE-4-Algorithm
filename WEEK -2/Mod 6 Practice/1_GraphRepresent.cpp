#include<bits/stdc++.h>
using namespace std;

// const int N = 1e3+7;
// int adjmat[N][N];

const int N = 1e6+7;
vector<pair<int,int> > adj[N];

int main()
{
    int n, m;
    cin>> n >> m;

    for(int i = 0; i<m; i++)
    {
        int u, v, w;
        cin>> u >> v >> w;
        // adjmat[u][v] = 1;
        // adjmat[v][u] = 1;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // for(int i = 1;  i<=n; i++)
    // {
    //     for(int j = 1; j<=n; j++)
    //     {
    //         cout<<adjmat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i = 1; i<=n; i++)
    {
        cout<<"adj["<<i<<"] : ";
        for( auto element : adj[i])
        {
            // cout<<element<<" ";
            cout<<"("<<element.first<<","<<element.second<<")"<<" ";
        }
        cout<<endl;
    }


    

    return 0;
}