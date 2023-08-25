
// Problem 2 , Version 2
//  version 1 in module 15, counting rooms.cpp

/*
মডিউল 15-2 ভিডিওতে দেখানো ওয়েতে 2D গ্রিডের উপর ট্রাভারস করতে পারেন। সোর্স নড দিয়ে ট্রাভারস করার পর যদি দেখেন ডেস্টিনেশন নড ভিজিটেড হয় তাহলে ইয়েস প্রিন্ট করবেন আর নাহলে নো প্রিন্ট করবেন।

*/

#include<bits/stdc++.h>
using namespace std;

int n, m; 
int s1,s2,d1,d2; 

const int N = 1e3+7; 
char ar[N][N]; 
bool visited[N][N];

vector<pair<int,int>> path ={{-1,0},{1,0},{0,-1},{0,1}}; 

bool isValid(int ci, int cj)
{
    if(ci >=0 and ci<n and cj >=0 and cj<m and ar[ci][cj] =='.')
        return true;

    else 
        return false;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    // comp.push_back({si,sj});
    

    // for(int i=0; i<path.size(); i++)
    for(auto var : path)
    {
        int ci = si + var.first;
        int cj = sj + var.second;

        if(isValid(ci,cj) and !visited[ci][cj])
        {
            dfs(ci,cj);
        }

    }
}



/*

// Test case from Asif Mohammad Sifat vaiya (support session)

10 10
.-..-.--..
..--......
...--..-..
....--..-.
-...--.-..
..--.----.
--.....-..
-........-
..--...---
.-.....-..
9 0
1 7
*/



int main()
{
    
   cin>> n >> m; 
   for(int i =0; i<n; i++)
   {
        for(int j = 0; j<m; j++)
        {
            cin >> ar[i][j]; 
        }
   }

    
    cin >> s1 >> s2; 
    cin >> d1 >> d2; 


    dfs(s1,s2);
    // cout<<visited[d1][d2]<<endl;
    if(visited[d1][d2]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

// if you want to see the logic (brute force) . Will you? 
    /*
    int cnt = 0; 
    bool flag = false;
    for(int i = 0;i<n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(!visited[i][j] and ar[i][j] != '-')
            {
                cnt++;
                same = 0;
                sVec.clear();
                dfs(i,j);

                
                for(auto vpair: comp)
                {
                    cout<<"("<<vpair.first<<","<<vpair.second <<")" <<" ";
                    
                    if(vpair.first == s1 and vpair.second == s2)
                    {
                        same =+2;
                    }
                    if(vpair.first == d1 and vpair.second == d2)
                    {
                        same +=2; 
                    }
                }
                cout<<endl;

                cout<<"same = "<<same<<endl;
                sVec.push_back(same);
                for(auto el : sVec)
                {
                    // cout<<el<<endl;
                    if(el == 4 )
                    flag = true;
                }

                comp.clear();
                
            }
        }
    }

    // cout<<cnt<<endl;


    // cout<<flag<<endl;
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    */ 
   
    

    return 0;
}
