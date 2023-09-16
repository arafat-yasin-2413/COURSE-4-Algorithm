// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long

// int main()
// {
//     ll n; 
//     cin >> n; 

//     ll fibo[n+1]; 
//     fibo[0] = 1; 
//     fibo[1] = 1; 

//     for(int i = 2; i<=n; i++)
//     {
//         fibo[i] = fibo[i-1]+fibo[i-2];
//     }

//     // for(int i = 0; i<=n;  i++)
//     // {
//     //     cout<<fibo[i]<<" "; 
//     // }
//     cout<<fibo[100]<<endl;
//     // cout<<min(30,30)<<endl;


//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int n; 
    cin >> n; 

    ll fibo[n+1];
    fibo[0] = 1; 
    fibo[1] = 1; 

    for(int i =2; i<=n; i++)
    {
        fibo[i] = fibo[i-1]+fibo[i-2]; 
    }

    // for(int i = 0; i<=n; i++)
    // {
    //     cout<<fibo[i]<<" ";
    // }
    // cout<<endl; 

    cout<< fibo[n] <<endl;

    return 0;
}