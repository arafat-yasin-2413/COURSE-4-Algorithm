#include<bits/stdc++.h>
using namespace std;
int totalCall;
int fibo (int n )
{
    totalCall++;
    if(n == 0 or n == 1) return 1; 
    int ans1 = fibo (n-1);
    int ans2 = fibo (n-2);
    return ans1 + ans2 ; 
}

int main()
{
    int n; 
    cin >> n ; 

    cout<<fibo(n)<<endl;
    cout<<"Total Call : "<<totalCall<<endl;  
    return 0;
}