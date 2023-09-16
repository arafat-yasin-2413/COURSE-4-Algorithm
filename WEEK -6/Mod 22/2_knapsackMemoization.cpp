#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int val[N];
int w[N];
int dp[N][N];

int knapsack(int n, int S)
{
    // আইটেম সংখ্যা শুন্য হয়ে গেলে বা ব্যাগের ক্যাপাসিটি শুন্য হয়ে গেলে 
    // জিরো রিটার্ন করবে।
    if(n == 0 or S == 0)
    {
        return 0; 
    }

    if(dp[n][S] != -1)
    {
        // যদি কেউ আগে একবার কল হয়ে থাকে তাহলে এখান থেকে ওই 
        // কলের রেজাল্ট টা জাস্ট রিটার্ন করে দিবো।
        return dp[n][S];
    }
    // সাইজ যদি রেঞ্জের মধ্যে থাকে তাইলে এই কন্ডিশনে ঢুকবো
    if (w[n - 1] <= S)
    {
        // নিলে চয়েজ-১
        // না নিলে চয়েজ-২
        int choice1 = val[n - 1] + knapsack(n - 1, S - w[n - 1]); 
        int choice2 = knapsack(n - 1, S);

        dp[n][S] = max(choice1,choice2);
        return dp[n][S];
    }

    // সাইজ যা খালি আছে তার চেয়ে বেশি সাইজ দরকার হলে জাস্ট অন্য আইটেম
    // নিয়ে কল দিবে। 
    else 
    {
        return dp[n][S] = knapsack(n-1,S); 
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

    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=S; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout<<knapsack(n, S)<<endl;

    return 0;
}