#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const long long INF = 1e18+8;
long long n, m; 
long long dist[N][N];

// void printMatrix()
// {
//     for(int i = 1;i<=n; i++)
//     {
//         for(int j = 1; j<=n;  j++)
//         {
//             if(dist[i][j] == INF)
//             {
//                 cout<<"-1"<<" ";
//             }
//             else 
//             {
//                 cout<<dist[i][j]<<" ";
//             }
            
//         }
//         cout<<endl; 
//     }
// }

void initializeMatrix()
{
    for(int i = 1; i<N; i++)
    {
        for(int j =1 ; j<N; j++)
        {
            if(i == j) 
            {
                dist[i][j] = 0; 
            }
            else 
            {
                dist[i][j]= INF;
            }
        }
    }
}

int main()
{

    cin >> n >> m; 
    
    initializeMatrix(); 
    
    
    for(int i = 1;i<=m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w; 
        if(w < dist[u][v])
        {
            dist[u][v] = w;
        }
        
    }

    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    
    // printMatrix(); 

    long long  q; 
    cin >> q; 
    while(q--)
    {
        long long src, desti;
        cin >> src >> desti;
        if(dist[src][desti] == INF)
        {
            cout<<"-1"<<endl;
        }
        else 
        {
            cout<<dist[src][desti]<<endl;
        }
        
    }


    
    

    return 0;
}