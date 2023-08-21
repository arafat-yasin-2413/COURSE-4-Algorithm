#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8;
vector<int> adj[N];
// vector< pair<int,int> > adj[N];
int main()
{
    int n, m;
    cin>> n>> m;

    for(int i =0;i<m; i++)
    {
        int u,v,w;
        cin>>u>> v ;
        // adj[u].push_back(make_pair(v,w));
        // adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
        adj[u].push_back(v);
    }

    // N = 1e5+8
    // N sized vector
    for(int i = 1;i<=n; i++)
    {
        cout<<"List " << i<< ": ";
        for(int j = 0; j< adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        // for(auto element : adj[i])
        // {
        //     cout<<"("<< element.first<<","<<element.second <<")"<<" "; 
        // }
        cout<<endl;
    }


    return 0;
}