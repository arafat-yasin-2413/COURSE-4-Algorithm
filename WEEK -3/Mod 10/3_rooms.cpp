#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+9;
vector<string> g;
int visited[N][N];
int n, m; 


bool isValid(int i, int j )
{
    return (i>=0 and i<n and j>=0 and j<m);
}

void dfs(int i , int j )
{
    // valid node kina
    if(!isValid(i,j))
        return;
    if(visited[i][j]) 
        return;
    if(g[i][j] == '#')
        return;

    
    visited[i][j] = true;
    

    dfs(i, j-1);
    dfs(i, j+1);
    dfs(i-1, j);
    dfs(i+1, j);
    
}

int main()
{
    int n, m; 
    cin >> n >> m;

    for(int i = 0;i<n; i++)
    {
        string x; 
        cin >> x; 
        g.push_back(x);
    }

    int ct=0;
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<m ; j++)
        {
            if(g[i][j] == '#') continue;
            if(visited[i][j]) continue;
            dfs(i,j);
            ct++; 
        }
        
    }
    

    cout<<ct<<endl;
    

    return 0;
}