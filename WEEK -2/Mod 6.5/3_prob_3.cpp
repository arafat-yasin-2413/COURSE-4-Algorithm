#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;
vector<int> adj[N];

const int Nmat = 1e3+8;
int adjmat [Nmat][Nmat];

int main()
{
    int n, m; 
    cin >>n >>m ; 

    for(int i = 1; i<=m ; i++)
    {
        int u, v; 
        cin >> u >> v; 

        adj[u].push_back(v);

    }

    for(int i =1; i<= n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int v : adj[i])
        {
            cout<<v<<" ";
        }
        cout<<endl;
    }

    // cout<<adj[1][0]<<endl;
    // cout<<adj[1][1]<<endl;

    // cout<<adj[2][0]<<endl;

    // cout<<adj[3][0]<<endl;
    // cout<<adj[3][1]<<endl;

    cout<<endl;
   
    for(int i =1; i<=n; i++)
    {
        for(int j = 0; j<adj[i].size(); j++)
        {
            // cout<<adj[i][j]<<" ";
            adjmat[i][adj[i][j]] = 1;
        }
        // cout<<endl;
    }


    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl; 
    }

    return 0;
}