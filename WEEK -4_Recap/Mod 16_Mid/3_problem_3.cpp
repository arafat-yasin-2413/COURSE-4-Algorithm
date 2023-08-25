#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+6;
int n, m;
char ar[N][N];
bool visited[N][N]; 
int cnt ; 
vector<pair<int,int>> comp;
vector<int> compSize;

vector<pair<int,int>> path = {{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int ci, int cj)
{
    if(ci >=0 and ci<n and cj >=0 and cj<m)
    return true;
    else 
        return false; 
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    comp.push_back({si,sj});
    for(auto v : path)
    {
        int ci = si + v.first;
        int cj = sj + v.second; 

        if(isValid(ci,cj) and !visited[ci][cj] and ar[ci][cj] == '.')
        {
            dfs(ci,cj); 
        }
    }

}


int main()
{
     
    cin >> n >>m ; 
    for(int i  = 0;i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> ar[i][j];
        }
    }

    // for(int i  = 0;i<n; i++)
    // {
    //     for(int j = 0; j<m; j++)
    //     {
    //         cout<< ar[i][j] ;
    //     }
    //     cout<<endl; 
    // }
    
    

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(!visited[i][j] and ar[i][j] == '.')
            {
                
                dfs(i,j);
                // cnt++;
                // for(auto v : comp)
                // {
                //     cout<<v.first<<","<<v.second<<" ";
                // }
                // cout<<endl;
                compSize.push_back(comp.size());

                comp.clear(); 


            }

        }
    }

    int mn = INT_MAX;
    for(auto el : compSize)
    {
        // cout<<el<<endl;
        mn = min(mn,el);
    }
    // cout<<mn<<endl;
    if(mn == INT_MAX) cout<<-1<<endl;
    else cout<<mn<<endl;
    
    


    return 0;
}