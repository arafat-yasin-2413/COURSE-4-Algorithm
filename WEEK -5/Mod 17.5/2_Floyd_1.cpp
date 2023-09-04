#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n; 
    int ar[n+1][n+1];
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cin>>ar[i][j];
        }
    }

    
    for(int k = 1; k<=n; k++)
    {
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                ar[i][j] = min(ar[i][j],ar[i][k]+ar[k][j]);
            }
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<= n; j++)
        {
            cout<<ar[i][j]<<" "; 
        }
        cout<<endl; 
    }


    return 0;
}