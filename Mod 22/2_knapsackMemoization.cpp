#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 8;
int val[N];
int w[N];

int knapsack(int n, int s)
{
    // base case
    if(n == 0 or s == 0) 
    {
        return 0; 
    }

    if (w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, 
        s - w[n - 1]) + val[n - 1];

        int op2 = knapsack(n - 1, s);

        return max(op1, op2);
    }

    else 
    {
        return knapsack(n-1,s); 
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int S;
    cin >> S;

    cout<<knapsack(n, S)<<endl;

    return 0;
}