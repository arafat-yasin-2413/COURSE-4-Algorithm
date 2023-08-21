#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
// যেহেতু গ্লোবালি ডিক্লেয়ার করতেছি, তাই সবগুলো ঘরে false ই থাকবে।

void dfs(int u)
{
    // kaj 1 : ei node a dhuke jei kaj ta korbo
    visited[u] = true;
    cout<<"Visiting Node "<<u <<endl;
    for(int v : adj[u])
    {
        // kaj 2 : node er new neighbour der kahce jabar agee

        if(visited[v] == false)
        {
            dfs(v);
        
    
        // cout<<v <<" ";
        // kaj 3 : ekta neighbour er sob kaj sesh kore ber hobar por
        } 
    }

    // kaj 4 : 
    // node u er kaj sesh korar agee
}

int main()
{
    int n, m;
    cin>>n >> m; 

    for(int i = 1; i<= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*for(int i = 1;i<=n; i++)
    {
        cout<<"List " << i<< ": ";
        // for(int j = 0; j< adj[i].size(); j++)
        // {
        //     cout<<adj[i][j]<<" ";
        // }
        for(int element : adj[i])
        {
            cout<<element<<" ";
        }
        cout<<endl;
    }*/

    dfs(1);

    cout<<endl<<"Visiting Array"<<endl;
    for(int i = 1; i<=n; i++)
    {
        cout<<"Node "<<i<<" status : "<< visited[i]<<endl;
    }
    

    return 0;
}