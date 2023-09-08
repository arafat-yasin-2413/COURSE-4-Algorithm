#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n ; 

    int v[n];
    for(int i = 0; i<n; i++)
    {
        cin >> v[i];
    }
    int w[n];
    for(int i = 0; i<n; i++)
    {
        cin>> w[i]; 
    }

    int S ; 
    cin >> S; 

    int dp[n+1][S+1]; 
    // base case conversion
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            if(i == 0 or j == 0)
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
                int op1 = dp[i-1][j-w[i-1]] + v[i-1]; 
                int op2 = dp[i-1][j]; 
                dp[i][j] = max(op1,op2) ; 
            }

            else 
            {
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }

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