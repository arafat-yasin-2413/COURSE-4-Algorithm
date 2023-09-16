#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int S, M;
        cin >> M;

        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        S = 1000 - M;
        bool dp[n + 1][S + 1];
        dp[0][0] = true;
        for (int i = 1; i <= S; i++)
        {
            dp[0][i] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= S; j++)
            {
                if (ar[i - 1] <= j)
                {
                    bool op1 = dp[i][j - ar[i - 1]];
                    bool op2 = dp[i - 1][j];
                    dp[i][j] = op1 || op2;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        //    for(int i = 0; i<=n; i++)
        //    {
        //        for(int j  = 0; j<=S; j++)
        //        {
        //            cout<<dp[i][j] <<" " ;
        //        }
        //        cout<<endl;
        //    }

        //    cout<<endl<<dp[n][S]<<endl;

        if (dp[n][S])
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
