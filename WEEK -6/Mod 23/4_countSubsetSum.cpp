#include<bits/stdc++.h>
using namespace std;

int n, S; 
int ar[1005];
int dp[1005][1005];

int countSubsetSum(int n, int S)
{
    if(n == 0)
    {
        if(S == 0)
        {
            return 1; 
        }

        else 
        {
            return 0;
        }
    }

    if(dp[n][S] != -1)
    {
        return dp[n][S];
    }

    if(ar[n-1] <= S)
    {
        int op1 = countSubsetSum(n-1, S-ar[n-1]);
        int op2 = countSubsetSum(n-1,S);

        return dp[n][S] = op1 + op2; 
    }


    else 
    {
        return dp[n][S] = countSubsetSum(n-1,S); 
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        cin >> ar[i]; 
    } 

    cin >> S; 

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            dp[i][j] = -1; 
        }
    }
    
    cout<<countSubsetSum(n,S)<<endl;

  

    return 0;
}