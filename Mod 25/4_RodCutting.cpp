#include<bits/stdc++.h>
using namespace std;

int n; 
int val[1000];
int w[1000];
int dp[1005][1005];

int unb_knap(int n, int S)
{
    if(n == 0 or S == 0)
    {
        return 0; 
    }

    if(dp[n][S] != -1)
    {
        return dp[n][S];
    }

    if(w[n-1] <= S)
    {
        int choice1 = val[n-1] + unb_knap(n,S-w[n-1]);
        int choice2 = unb_knap(n-1,S);

        return dp[n][S] = max(choice1,choice2);
    }

    else 
    {
        return dp[n][S] = unb_knap(n-1,S); 
    }
}


int main()
{
    cin >> n; 
    for(int i = 0; i<n; i++)
    {
        cin>> val[i];
        w[i] = i+1; 
    }

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<unb_knap(n,n)<<endl;

    return 0;
}