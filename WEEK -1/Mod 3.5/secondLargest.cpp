#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int ar[n];

    for(int i =0;i<n;i++)
    {
        cin>> ar[i];
    }
    // cout<<n<<endl;
    int first = INT_MIN;
    int second = INT_MIN;

    
    for(int i = 0; i<n; i++)
    {
        if(ar[i] > first) 
        {
            if(i > 0 and ar[i] > first)
            {
                second = first;
            } 
            first = ar[i];
            
        }
  
    }

    cout<<"first = "<<first<<endl<<"second = "<<second<<endl;
    // cout<<"second = "<<second<<endl;

    return 0;
}