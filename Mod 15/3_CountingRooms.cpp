#include<bits/stdc++.h>
using namespace std;
 
int n, m; 
int cnt ; 
 
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
5 8
########
#..#...#
####.#.#
#..#...#
########
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
 
    // for(int i = 1; i<=n; i++)
    // {
    //     for(int j = 1; j<=m; j++)
    //     {   
    //         cout<< ar[i][j];   
    //     }
    //     cout<<endl; 
    // }
 
 
    
    for(int i = 0;i<n; i++)
    {
        for(int j = 0 ; j<m; j++)
        {
            if(!visited[i][j] and ar[i][j] != '#')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
 
    cout<<cnt<<endl;
 
    return 0;
}






















































/*



// problem 2 , version 1

#include<bits/stdc++.h>
using namespace std;

int n, m; 
int s1,s2,d1,d2; 
int same = 0; 

const int N = 1e3+7; 
char ar[N][N]; 
bool visited[N][N];
vector<int> sVec(N);
vector<pair<int,int>> comp;

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
    comp.push_back({si,sj});
    

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
5 8
########
#..#...#
####.#.#
#..#...#
########
*/

/*
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


/*
    1. নেস্টেড লুপ চালিয়ে সব সেল এ যাবো। 

    2. সেল টা যদি ভিজিটেড না হয় এবং মোস্ট ইম্পরট্যান্টলি '#' না হয় কেবল তখনই 
        সেই সেল থেকে dfs কল দিবো। 


*/

/*
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

    // for(int i = 1; i<=n; i++)
    // {
    //     for(int j = 1; j<=m; j++)
    //     {   
    //         cout<< ar[i][j];   
    //     }
    //     cout<<endl; 
    // }


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
   
    

    return 0;
}
*/