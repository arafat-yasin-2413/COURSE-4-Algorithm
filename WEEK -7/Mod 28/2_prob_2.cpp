#include <bits/stdc++.h>
using namespace std;

int n,s, S;
int ar[1005];
int dp[1005][1005];

int main()
{

    int t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        S = 1000-s;

        dp[0][0] = 0;
        for (int i = 1; i <= S; i++)
        {
            dp[0][i] = INT_MAX - 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= S; j++)
            {
                if (ar[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - ar[i - 1]], dp[i - 1][j]);
                }

                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        if (dp[n][S] == INT_MAX - 1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dp[n][S] << endl;
        }

        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= S; j++)
        //     {
        //         if (dp[i][j] == INT_MAX - 1)
        //         {
        //             cout << "X"
        //                  << " ";
        //         }
        //         else
        //         {
        //             cout << dp[i][j] << " ";
        //         }
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}