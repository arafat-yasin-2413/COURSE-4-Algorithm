#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int n, S;
int ar[1006];


bool subsetSum(int n, int S)
{
    if(n == 0)
    {
        if(S == 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    if(dp[n][S] != -1)
    {
        return dp[n][S]; 
    }

    if(ar[n-1] <= S)
    {
        bool op1 = subsetSum(n-1,S-ar[n-1]);
        bool op2 = subsetSum(n-1,S);

        return dp[n][S] = op1 or op2;
    }

    else 
    {
        return dp[n][S]= subsetSum(n-1,S);
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


    if(subsetSum(n,S)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;




    return 0;
}