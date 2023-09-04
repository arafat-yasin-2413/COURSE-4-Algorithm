#include<bits/stdc++.h>
using namespace std;

#define pii pair< int,pair<int,int> >

const int N = 1e5+5;
int n, m ; 
vector<pair<int,int>> adj[N];
bool visited[N];

vector<pii> edgeList;


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

/*
8
11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2

output
1 5 2
1 2 4
5 4 5
4 8 9
8 6 2
6 7 1
4 3 11
*/

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
    for(auto e : edgeList)
    {
        cout<<e.second.first<<" "<<e.second.second<<" "<<e.first<<endl; 
    }


    return 0;
}