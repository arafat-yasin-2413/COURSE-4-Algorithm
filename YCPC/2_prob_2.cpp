#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    int lines = 11-5;
    int s = lines - 1, k = 1;

    for (int i = 1; i <= lines; i++)
    {
        /// space print kori
        for (int j = 1; j <= s; j++)
        {
            printf(" ");
        }

        /// star print kori
        for (int j = 1; j <= k; j++)
        {
            printf("*");
        }

        s--;
        k += 2;
        cout << endl;
    }
    

    int spc2 = 5;
    for (int i = 1; i <= 5; i++)
    {
        for (int k = 1; k <= spc2; k++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}