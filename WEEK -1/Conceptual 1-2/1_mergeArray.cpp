#include<bits/stdc++.h>
using namespace std;

void mergeTwoArrays(int ar1[],int ar2[],int sz1,int sz2,int mergeArr[],int totalSize)
{
    int i = 0, j = 0, k = 0;
    while(i<sz1 or j < sz2)
    {
        if(ar1[i] <= ar2[j])
        {
            mergeArr[k]= ar1[i];
            i++;
        }
        else 
        {
            mergeArr[k] = ar2[j];
            j++;
        }

        k++;
    }

    cout<<"i = "<<i<<" "<<"j = "<<j <<" "<<"k = "<<k <<endl;


}

void printArray(int a[],int sz)
{
    for(int i = 0; i<sz; i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<endl;
}

int main()
{
    int ar1[] = {1,3,5,7,9};
    // cout<<sizeof(ar)/sizeof(ar[0])<<endl;
    int sz1 = sizeof(ar1) / sizeof(ar1[0]);

    int ar2[] = {2,4,6,8,10};
    int sz2 = sizeof(ar2)/ sizeof(ar2[0]);

    int totalSize = sz1+sz2;
    int mergeArr[totalSize];

    mergeTwoArrays(ar1,ar2,sz1,sz2,mergeArr,totalSize);
    printArray(mergeArr,totalSize);


    return 0;
}