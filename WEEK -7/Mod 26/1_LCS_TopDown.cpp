#include<bits/stdc++.h>
using namespace std;

string a, b; 


int LCS(int n, int m)
{
    // n = size of string a
    // m = size of string b

    // base case: if any string reach null then no lcs can be form
    if(n == 0 or m == 0)
    {
        return 0; 
    }

    // if last index is same on both strings then we will eliminate last 
    // index from both of the string and add +1
    if(a[n-1] == b[m-1])
    {
        int ans = LCS(n-1,m-1);
        return ans+1;
    }

    // if the last indexes are not same then omit from string a and 
    // omit from string b
    else 
    {
        int ans1 = LCS(n-1,m);
        int ans2 = LCS(n,m-1);
        return max(ans1,ans2);
    }
}

int main()
{
    cin >> a >> b; 

    cout<<LCS(a.size(),b.size())<<endl;

    return 0;
}