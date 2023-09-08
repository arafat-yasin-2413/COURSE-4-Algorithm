#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subsetSum(int n, int S, int a[])
{
    if (n == 0)
    {
        if (S == 0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    if (dp[n][S] != -1)
    {
        return dp[n][S];
    }

    if (a[n - 1] <= S)
    {
        bool op1 = subsetSum(n - 1, S - a[n - 1], a);
        bool op2 = subsetSum(n - 1, S, a);

        return dp[n][S] = op1 or op2;
    }

    else
    {
        return dp[n][S] = subsetSum(n - 1, S, a);
    }
}

int main()
{

    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {

        int n, target;
        cin >> n >> target;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int s = 1000 - target;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }

        if (subsetSum(n, s, a))
        {
            cout << "YES" << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
