/*
||-----------------------------------||
||        Rahat Khan Pathan          ||
||         Programming Hero          ||
||-----------------------------------||
*/
#include<bits/stdc++.h>
#define ll long long int
#define pub push_back
#define pob pop_back
#define PI 3.14159265359
#define vll vector<ll>
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique(All(X)),(X).end())
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pi pair<ll,ll>
#define vpair vector<pair<ll,ll>>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define minus cout<<-1<<endl
using namespace std;
const int N = 1e5+5;
vector<int> v[N];
vector<int> dis(N,-1);
bool vis[N];
int par[N];
int n;
void bfs(ll s)
{
    queue<int> q; 
    q.push(s);
    vis[s]=true;
    dis[s]=0;
    par[s]=-1;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<v[p].size();i++)
        {
            ll c=v[p][i];
            if(!vis[c])
            {
                vis[c]=true;
                q.push(c);
                par[c]=p;
                dis[c]=dis[p]+1;
            }
        }
    }
    if(dis[n]==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> ans;
    int pp=n;
    while(pp!=-1)
    {
        ans.push_back(pp);
        pp=par[pp];
    }
    reverse(All(ans));
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

}
int main()
{
    fast;
    int e; cin>>n>>e;
    while(e--)
    {
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    return 0;
}



/*
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adj[N];
// vector<bool> visited(N,false);
vector<bool> visited(N, 0);
vector<int> level(N, 0);
vector<int> parent(N, -1);

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            level[v] = level[u] + 1;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    cout << level[n] + 1 << endl;

    int cur = n;
    vector<int> path;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());
    if (path.size() == 0)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int el : path)
        {
            cout << el << " ";
        }
    }

    return 0;
}
*/