#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int adjMat[N][N];

int main()
{
    int n, m; 
    cin >> n >>m; 

    for(int i = 1; i<=m; i++)
    {
        int u, v; 
        cin >> u >> v; 
        adjMat[u][v] = 1;
        // adjMat[v][u] = 1; 
    }

    for(int i = 1;i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(adjMat[i][j] != 0)
            cout<<"adjMat["<<i<<"]["<<j<<"] : "<<adjMat[i][j]<<" ";
            // cout<<adjMat[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}