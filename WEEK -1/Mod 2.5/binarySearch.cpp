#include<bits/stdc++.h>
using namespace std;

// int binarySearch(vector<int> &v,int l, int r, int val)
// {
//     int mid = (l+r)/2;
//     if(v[mid] == val)  return mid;
//     else if( val < v[mid] )
//     {
//         binarySearch(v,0,mid-1,val);
//     }
//     else if(val > v[mid]) 
//     {
//         binarySearch(v,mid+1,r,val);
//     }
// }

int binarySearch(vector<int> &v,int l, int r, int x)
{
    if(l > r ) return -1;
    int mid = (l+r)/2;
    
    if(v[mid] == x) return mid; 

    else if(x < v[mid])
    {
        int l = binarySearch(v,l,mid-1,x); 
        return l;     
    }
    
    else if(x > v[mid])
    {
        return binarySearch(v,mid+1,r,x);     
    }
    

}


int main()
{
    vector<int> v = {-1,0,3,5,9,12};
    // cout<<v.size();
    int sz = v.size();
    int val;cin>>val;

    int idx = binarySearch(v,0,sz-1,val);
    cout<<idx<<endl;


    return 0;
}