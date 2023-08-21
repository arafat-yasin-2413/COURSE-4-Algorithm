#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n)
{
    for(int i =0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl; 
}

int main()
{
    int n;cin>>n;
    int ar[n];
    for(int i =0; i<n;i++)
        cin>>ar[i];

    // sort(ar,ar+n);

    vector<int> v;
    for(int i = 0; i<n; i++)
    {
        v[ar[i]]++;
    }

    
    printArray(ar,n);

    return 0;
}