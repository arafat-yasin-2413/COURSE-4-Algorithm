#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l, int r, int mid)
{
    int leftSize = mid-l +1; 
    int L[leftSize];

    for(int i = l,j = 0;i<=mid; i++,j++)
    {
        L[j] = a[i];
    }

    int rightSize = r-mid; 
    int R[rightSize];

    for(int i = mid+1,j=0;i<=r;i++,j++)
    {
        R[j] = a[i];
    }

    L[leftSize] = INT_MAX;
    R[rightSize] = INT_MAX;

    int lp = 0, rp = 0; 
    for(int i = l; i<=r; i++)
    {
        if(L[lp] <= R[rp])
        {
            a[i] = L[lp];
            lp++;
        }

        else 
        {
            a[i] = R[rp];
            rp++;
        }
    }


}


void mergeSort(int a[],int l, int r)
{
    if(l<r)
    {
        int  mid = (l+r)/2; 
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,r,mid);
    }
}















void printArray(int arr[],int sz)
{
    for(int i = 0; i<sz; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
}

int main()
{
    int n; 
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++)
    {
        cin>> a[i];
    }

    mergeSort(a,0,n-1);

    printArray(a,n);





    return 0;
}