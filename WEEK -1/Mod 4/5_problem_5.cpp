#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n)
{
    for(int i = 0; i<n; i++)
        cout<<a[i]<< " ";
    cout<<endl; 
}

void mergeTwoArrays(int n, int m, int a[],int b[])
{
    int totalSize = n+m;
    int resultArr[totalSize] ;
    a[n] = INT_MIN;
    b[m] = INT_MIN;

    int lp = 0, rp = 0;
    for(int i = 0; i<totalSize; i++)
    {
        if(a[lp] >= b[rp])
        {
            resultArr[i] = a[lp];
            lp++;
        }

        else 
        {
            resultArr[i] = b[rp];
            rp++;
        }
    }


    printArray(resultArr,totalSize);

}



int main()
{
    int n, m;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++)
        cin>>arr[i];
    cin>>m;
    int brr[m];
    for(int i  =0; i<m; i++)
        cin>>brr[i];

    // printArray(arr,n);
    // printArray(brr,m);

    mergeTwoArrays(n, m, arr,brr);


    return 0;
}