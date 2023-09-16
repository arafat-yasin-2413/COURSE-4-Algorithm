#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int dp[N];

bool knapsack(int n, int S)
{
    if (n == S)
    {
        return true;
    }
    
    if(n > S)
    {
        return false;
    }
    
    if(dp[n] != -1)
    {
        return dp[n];
    }
    
    if (n <= S)
    {
        bool choice1 = knapsack(n + 3, S);
        bool choice2 = knapsack(n * 2, S);

        dp[n] = (choice1 or choice2);
        return dp[n];
    }
    
    return dp[n];
    
   
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int S;
        cin >> S;
        
        for(int i = 0; i<=S; i++)
        {
            dp[i] = -1;
        }
        
        if (knapsack(1, S))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}