#include<bits/stdc++.h>
using namespace std;

const int N= 1e3+7;
int adjmat[N][N];

int main()
{
    int n;
    cin>>n;
    int m ; cin>>m;

   
    for(int i = 1; i<=m ; i++)
    {
        int u, v,w;
        cin>>u>>v>>w;
        adjmat[u][v] = w;
        // adjmat[v][u] = 1; 
    }
    


    for(int i=1;i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}