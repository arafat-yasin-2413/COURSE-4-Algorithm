#include <bits/stdc++.h>
using namespace std;

int n, S;
int val[1005];
int w[1005];
int dp[1005][1005]; 


int main()
{
    cin >> n >> S;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            if(i == 0 or j== 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=S; j++)
        {
            if(w[i-1] <= j)
            {
                dp[i][j] = max(val[i-1]+dp[i][j-w[i-1]],dp[i-1][j]);
            }

            else 
            {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    
    cout<<dp[n][S]<<endl;

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            cout<<dp[i][j]<<" "; 
        }
        cout<<endl;
    }

    return 0;
}