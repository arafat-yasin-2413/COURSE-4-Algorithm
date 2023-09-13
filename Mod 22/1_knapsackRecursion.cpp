#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int val[N];
int w[N];


// Base case ডিপেন্ড করে যেই ভ্যালুগুলো চেঞ্জ হচ্ছে তাদের উপর। 
// Base case কে মিনিমাম পসিবল ভ্যালু ও বলা যেতে পারে। 


// 0 based Array used
int knapsack(int n, int S)
{
    // আইটেম সংখ্যা শুন্য হয়ে গেলে বা ব্যাগের ক্যাপাসিটি শুন্য হয়ে গেলে 
    // জিরো রিটার্ন করবে।
    if(n == 0 or S == 0)
    {
        return 0; 
    }

    // সাইজ যদি রেঞ্জের মধ্যে থাকে তাইলে এই কন্ডিশনে ঢুকবো
    if (w[n - 1] <= S)
    {
        // নিলে চয়েজ-১
        // না নিলে চয়েজ-২
        int choice1 = val[n - 1] + knapsack(n - 1, S - w[n - 1]); 
        int choice2 = knapsack(n - 1, S);

        return max(choice1,choice2);
    }

    // সাইজ যা খালি আছে তার চেয়ে বেশি সাইজ দরকার হলে জাস্ট অন্য আইটেম
    // নিয়ে কল দিবে। 
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

    int S;
    cin >> S;

    cout << knapsack(n, S) << endl;

    return 0;
}