#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
long long dp[N];
int totalRecursiveCall;
void initializeWithMinusOne(int sz)
{
    for(int i =0; i<=sz; i++)
    {
        dp[i] = -1; 
    }
}

long long fibo(int n )
{
    totalRecursiveCall++;
    if(n == 0 or n == 1)
    {
        dp[n] = 1;
        return 1; 
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    long long ans1 = fibo(n-1);
    long long ans2 = fibo(n-2); 
    dp[n] = ans1+ans2;
    return dp[n];
}

int main()
{
    
    int n ; 
    cin >> n; 
    initializeWithMinusOne(n);
    
    fibo(n);

    // for(int i =0; i<n; i++)
    // {
    //     cout<< "dp["<<i<<"]"<<" --> " << dp[i]<<endl; 
    // }

    // cout<<"Total Number of Calls : "<<totalRecursiveCall<<endl;

    cout<<dp[100]<<endl;

    return 0;
}