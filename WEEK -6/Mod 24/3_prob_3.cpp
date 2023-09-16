#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int n;
        cin >> n;

        int sum = 0;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
            sum += ar[i];
        }

        if (sum % 2 == 0)
        {
            int middle = sum / 2;
            bool dp[n + 1][middle + 1];

            dp[0][0] = true;

            for (int i = 1; i <= middle; i++)
            {
                dp[0][i] = false;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j <= middle; j++)
                {
                    if (ar[i - 1] <= j)
                    {
                        bool op1 = dp[i - 1][j - ar[i - 1]];
                        bool op2 = dp[i - 1][j];

                        dp[i][j] = (op1 or op2);
                    }

                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            if (dp[n][middle])
            {
                cout << "YES" << endl;
            }

            else
            {
                cout << "NO" << endl;
            }
        }

        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}