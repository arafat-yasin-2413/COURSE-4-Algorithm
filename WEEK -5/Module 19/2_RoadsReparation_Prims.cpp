#include<bits/stdc++.h>
using namespace std;

#define pii pair< int,pair<int,int> >

const int N = 1e5+5;
int n, m ; 
vector<pair<int,int>> adj[N];
bool visited[N];

vector<pii> edgeList;
int cnt; 


void prims(int src)
{
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    pq.push({0,{src,src}});

    while(!pq.empty())
    {
        // কোনো একটা edge কে নিবো। 

        // top nicchi
        auto parent = pq.top();
        pq.pop();


        int w = parent.first;
        int u = parent.second.first;
        int v = parent.second.second; 

        //  v নিবো 

        // edge টা ভিজিট না হয়ে থাকলে তাকে ভিজিট করে দিবো।
        if(visited[v]) continue;
        visited[v] = true;
        cnt++; 

        
        
        edgeList.push_back({w,{u,v}});
        // v এর adjacency list থেকে সবাইকে নিয়ে এসে (visited na hoile) প্রায়োরিটি কিউ তে পুশ করবো।
        for(auto el : adj[v])
        {

            if(!visited[el.first])
            {
                pq.push({el.second,{v,el.first}});
            }
        }  

        // final / edge list এ পুশ করবো। 



    }


}

int main()
{
    
    cin >> n >> m; 
    for(int i = 1;i<=m; i++)
    {
        int u, v,w; 
        cin >> u >> v >> w; 
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // cout<<visited[4]<<endl;


    // for(int i = 1; i<=n; i++)
    // {
    //     cout<<"List "<<i<<": "; 
    //     for(auto el : adj[i])
    //     {
    //         cout<<"("<<el.first<<","<<el.second<<")"<< " ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"********************************************"<<endl;


    prims(1);

    edgeList.erase(edgeList.begin());
    long long int cost = 0;
    for(auto e : edgeList)
    {
        // cout<<e.second.first<<" "<<e.second.second<<" "<<e.first<<endl; 
        cost+=(long long int)(e.first);
    }

    // cout<<cnt<<endl; 
    if(cnt== n) cout<<cost<<endl;
    else cout<<"IMPOSSIBLE"<<endl;


    for(int i = 1;i<=n;i++)
    {
        cout<<"Visit Status of "<<i<<": "<<visited[i]<<endl;
    }


    return 0;
}