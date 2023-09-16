#include <bits/stdc++.h>
using namespace std;

int n, S;
int val[1005];
int w[1005];
int dp[1005][1005];

int unboundedKnapsack(int n, int S)
{
    if(n == 0 or S == 0)
    {
        return 0; 
    }

    if(dp[n][S] != -1)
    {
        return dp[n][S];
    }

    if (w[n - 1] <= S)
    {
        int choice1 = val[n - 1] + unboundedKnapsack(n, S - w[n - 1]);
        int choice2 = unboundedKnapsack(n - 1, S);
        return dp[n][S] = max(choice1,choice2);
    }

    else 
    {
        return dp[n][S] = unboundedKnapsack(n-1,S);
    }
}

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
            dp[i][j] = -1;
        }
    }

    cout<<unboundedKnapsack(n,S)<<endl;

    return 0;
}