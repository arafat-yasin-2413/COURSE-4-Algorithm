#include<bits/stdc++.h>
using namespace std;

int binary_search(int ar[],int l, int r, int x)
{
    int cnt = 0;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(x == ar[mid])
        {
            cnt++;
            if( mid>0 and  x == ar[mid-1])
            {
                cnt++;
            }

            if( mid <= r and  x == ar[mid+1])
            {
                cnt++;
            }
            break;
        }
        else if(x < ar[mid])
        {
            r = mid-1;
        } 
        else 
        {
            l = mid+1;
        }
    }
    // cout<<cnt<<endl;
    return cnt; 
}


int main()
{
    int n;cin>>n;
    int ar[n];
    for(int i = 0; i<n; i++)
        cin>>ar[i];
    
    int x ; cin>> x; 
    int cnt = binary_search(ar,0,n-1,x);
    if(cnt == 1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;


    return 0;
}