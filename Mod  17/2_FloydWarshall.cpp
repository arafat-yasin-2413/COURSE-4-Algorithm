#include<bits/stdc++.h>
using namespace std;

int n, m ; 
const int N = 1e3+5;
const int INF = 1e9+9;
int dist[N][N];

int main()
{

    for(int i = 0;i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            dist[i][j] = INF;
            if(i == j)
            {
                dist[i][j] = 0;
            }
        }
    }

    
    cin >> n >> m ; 

    for(int i = 1 ; i<=m; i++)
    {
        int u, v , w; 
        cin >> u >> v >> w; 
        dist[u][v] =  w;
    }


    // implementing floyd warshall here
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][k]+dist[k][j], dist[i][j]);
            }
        }
    }


    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(dist[i][j] == INF)
            {
                cout<<"X"<<" ";
            }
            else 
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }


    


    return 0;
}