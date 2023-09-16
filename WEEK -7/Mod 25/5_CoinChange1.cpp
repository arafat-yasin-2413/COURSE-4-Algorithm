#include<bits/stdc++.h>
using namespace std;

int n,S;
int w[1005]; 
int dp[1005][1005]; 

int main()
{
    cin>> n; 
    for(int i = 0; i<n; i++)
    {
        cin>> w[i]; 
    }
    cin>> S; 

    dp[0][0] = 1; 
    for(int i =1 ; i<=S; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            if(w[i-1] <= j)
            {
                dp[i][j] = dp[i][j-w[i-1]] + dp[i-1][j];

            }
            else 
            {
                dp[i][j] = dp[i-1][j];
            }
        }


        
    }

    cout<<dp[n][S]<<endl;

    return 0;
}