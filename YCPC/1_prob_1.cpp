#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,res;
    long long int t; 
    cin >> t; 
    for(int i = 1; i<=t; i++)
    {
        cin >> a >> b; 
        res = (a*b)%100;
        cout<<res<<endl;
    }

    

    return 0;
}