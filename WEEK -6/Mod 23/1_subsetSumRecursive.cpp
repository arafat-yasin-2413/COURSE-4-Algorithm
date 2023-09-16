#include<bits/stdc++.h>
using namespace std;

int n, S;
int ar[1006];


bool subsetSum(int n, int S)
{
    if(n == 0)
    {
        if(S == 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }

    if(ar[n-1] <= S)
    {
        bool op1 = subsetSum(n-1,S-ar[n-1]);
        bool op2 = subsetSum(n-1,S);

        return op1 or op2; 
    }

    else 
    {
        return subsetSum(n-1,S);
    }
}

int main()
{
     
    cin >> n; 

    
    for(int i = 0; i<n; i++)
    {
        cin >> ar[i]; 
    }

    
    cin >> S;

    if(subsetSum(n,S)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;




    return 0;
}