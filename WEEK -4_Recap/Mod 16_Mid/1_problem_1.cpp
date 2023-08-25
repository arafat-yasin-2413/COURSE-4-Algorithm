#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+8; 
vector<pair<int,int>> edgeList;

int main()
{
    int m; 
    cin >> m; 

    for(int i = 1 ; i<=m; i++)
    {
        int u, v ; 
        cin >> u >> v ;

        edgeList.push_back({u,v}); 
    }

    // priority_queue<pair<int,int>,vector<pair<int,int>, greater<pair<int,int>> pq;
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    for(auto v : edgeList)
    {
        pq.push({v.first,v.second});
        // cout<<"("<<v.first<<","<<v.second<<")"<<endl; 
    }

    while(!pq.empty())
    {
        auto el = pq.top();
        pq.pop();
        cout<<el.first<<" "<<el.second<<endl;
    }

    return 0;
}