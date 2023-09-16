#include<bits/stdc++.h>
using namespace std;
int n , S; 
int ar[1005];
int dp[1005][1005];


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
            if(i == 0 and j == 0)
            {
                dp[i][j] = 1; 
            }
        }
    }

    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            if(ar[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-ar[i-1]];
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
            // cout<<dp[i][j]<<" "; 
            if(dp[i][j] == 0) 
            {
                cout<<"F"<<" "; 
            }

            else if(dp[i][j] == 1)
            {
                cout<<"T"<<" "; 
            }
        }
        cout<<endl; 
    }

    return 0;
}