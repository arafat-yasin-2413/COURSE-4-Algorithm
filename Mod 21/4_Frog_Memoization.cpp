#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
int a[N]; 
int dp[N];


int solve(int n )
{
    if(n == 1)
    {
        return 0;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }
    else if(n == 2)
    {
        dp[n] = abs(a[2]-a[1]);
        return dp[n]; 
    }

    else 
    {
        int choice1 = solve(n-1) + abs(a[n]-a[n-1]);
        int choice2 = solve(n-2) + abs(a[n]-a[n-2]);
        dp[n] = min(choice1,choice2);
        return dp[n];
    }
}

int main()
{
    int n; 
    cin >> n ; 

    for(int i = 1;i<=n;i++)
    {
        cin >> a[i]; 
        // initializing dp also
        dp[i] = -1; 
    }
    // cout<<dp[1]<<endl;
    // cout<<dp[2]<<endl;
    // cout<<dp[3]<<endl;
    // cout<<dp[4]<<endl;

    cout<<solve(n)<<endl;



    return 0;
}