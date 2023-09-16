#include<bits/stdc++.h>
using namespace std;

string a, b; 
int dp[1005][1005]; 

int main()
{
    cin >> a >> b; 

    // base case
    for(int i = 0; i<=a.size(); i++)
    {
        for(int j = 0; j<=b.size(); j++)
        {
            if(i == 0 or j == 0)
            {
                dp[i][j] = 0; 
            }
        }
    }

    for(int i = 1; i<=a.size(); i++)
    {
        for(int j = 1; j<=b.size(); j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1; 
            }

            else  
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    

    // cout<<dp[a.size()][b.size()]<<endl;

    int i = a.size(); 
    int j = b.size(); 

    string ans; 
    while(i != 0 and j != 0)
    {
        if( a[i-1] == b[j-1] )
        {
            ans+=a[i-1]; 
            i--;
            j--;
        }

        else 
        {
            if(dp[i][j-1] > dp[i-1][j])
            {
                j--;
            }

            else 
            {
                i--;
            }
        }
    }
    
    reverse(ans.begin(),ans.end()); 
    cout<<ans<<endl;
    

    return 0;
}