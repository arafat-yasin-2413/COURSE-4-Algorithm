#include <bits/stdc++.h>
using namespace std;

int n, M, S;
int ar[1005];
int dp[1005][1005];
int limit = 1000000007;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> M;
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        S = 1000 - M;
        dp[0][0] = 1;
        for (int i = 1; i <= S; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= S; j++)
            {
                if (ar[i - 1] <= j)
                {
                    dp[i][j] = ((dp[i][j - ar[i - 1]]) % limit + (dp[i - 1][j]) % limit) % limit;
                }

                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        cout << dp[n][S] << endl;
    }

    return 0;
}