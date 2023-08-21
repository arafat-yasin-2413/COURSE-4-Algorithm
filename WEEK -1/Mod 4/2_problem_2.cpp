#include<bits/stdc++.h>
using namespace std;

// iterative
// int binary_Search(int ar[],int l, int r,int x)
// {
//     while(l <= r)
//     {
//         int mid = (l+r)/2;
//         if(x == ar[mid])
//         {
//             return mid;
//         }

//         else if(x < ar[mid])
//         {
//             r = mid-1;
//         }

//         else if( x > ar[mid])
//         {
//             l = mid+1;
//         }
//     }

//     return -1;
// }








// recursive
int binarySearch(int ar[],int l, int r, int x)
{
    if(l > r ) return -1;
    int mid = (l+r)/2;
    
    if(ar[mid] == x) return mid; 

    else if(x < ar[mid])
    {
        int left= binarySearch(ar,l,mid-1,x);
              return left;
    }
    
    else if(x > ar[mid])
    {
        int right = binarySearch(ar,mid+1,r,x);
            return right;
    }

}

int main()
{
    int n ; cin>> n;
    int ar[n];
    for(int i = 0; i<n; i++)
    {
        cin >> ar[i];
    }

    int x; cin >>x; 
    int idx = binarySearch(ar,0,n-1,x);
    cout<<idx<<endl;
    // if(idx > 0 ) cout<<idx<<endl;
    // else cout<<"Not Found"<<endl;
    


    return 0;
}