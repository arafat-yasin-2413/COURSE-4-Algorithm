#include <bits/stdc++.h>
using namespace std;
// #define pi pair<int,int>
vector<pair<int,int>> path ={{-1,0},{1,0},{0,-1},{0,1}}; 
const int N = 1e3+5;
bool visited[N][N];
int dist[N][N]; 
int n, m;

bool isValid(int ci, int cj)
{
    if(ci>=0 and ci<n and cj>=0 and cj<m)
    return true;
    else return false; 
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q; 
    q.push({si,sj});
    dist[si][sj] = 0; 
    visited[si][sj] = true;

    while(!q.empty())  
    {
        pair<int,int> parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop(); 

        // children 4 ta (left,right,up,down)
        for(int i = 0; i<m; i++)
        {
            // ekta ekta kore path ber kori
            pair<int,int> p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second;
            // ekhon dekhbo j children er i-th and j-th index valid kina
            // index er validity agee check korte hobe
            // tarpor visited a oi cell ta k true kore dite hobe

            // cout<<ci<<" "<<cj<<endl;
            if(isValid(ci,cj) and !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci,cj});
                dist[ci][cj] = dist[pi][pj] + 1; 
            } 
        } 
    }
}


int main()
{
    
    cin >> n >> m;

    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout<<endl;
    // }

    int si, sj; 
    cin >> si >> sj; 

    bfs(si,sj);

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            // cout<<dist[i][j]<<" ";
            cout<<"dist["<<i<<"]["<<j<<"] : "<<dist[i][j]<<endl;
        }
        // cout<<endl; 
    }


    return 0;
}