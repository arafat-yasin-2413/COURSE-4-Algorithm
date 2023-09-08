#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int val[N];
int w[N];

// 0 based Array used

int knapsack(int n,int S)
{
    if(n == 0 or S == 0)
    {
        return 0; 
    }

    if(w[n-1] <= S)
    {
        int op1 = val[n-1] + knapsack(n-1, S-w[n-1]);

        int op2 = knapsack(n-1,S);

        return max(op1,op2);
    }

    else 
    {
        return knapsack(n-1,S);
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

    int S ; 
    cin >> S; 

    cout<<knapsack(n,S)<<endl;

    return 0;
}