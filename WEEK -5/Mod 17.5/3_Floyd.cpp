#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 8;
int dist[101][101];

int main()
{
    int mx = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
            if(dist[i][j] == -1) 
            {
                dist[i][j] = INF; 
            }
        }
    }

    // for(int i = 1;i<=n; i++)
    // {
    //     for(int j = 1;j<=n; j++)
    //     {
    //         if(dist[i][j] == INF)
    //         {
    //             cout<<"X"<<" "; 
    //         }
    //         else 
    //         cout<<dist[i][j]<<" "; 
    //     }
    //     cout<<endl; 
    // }

    

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]); 
            }
        }
    }

    for(int i = 1;i<=n ;i++)
    {
        for(int j = 1; j<=n;j++)
        {
            if(dist[i][j] != INF and dist[i][j] > mx)
            {
                mx = dist[i][j]; 
            }
        }
    }

    cout<<mx<<endl;


    return 0;
}