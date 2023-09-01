#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int, int>, int>

const int N = 1e3 + 13;
int n, m;
const long long INF = 1e18 + 8;
vector<pii> edgeList;
long long dist[N];

void initializeDistance()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
}

void BellmanFord(int src)
{
    initializeDistance();

    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (auto el : edgeList)
        {
            long long u = el.first.first;
            long long v = el.first.second;
            long long w = el.second;

            if (dist[u] != INF and dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({{u, v}, w});
    }

    // for(auto el : edgeList)
    // {
    //     cout<<el.first.first<<" "<<el.first.second<<": "<<el.second<<endl;
    // }

    int src;
    cin >> src;
    BellmanFord(src);

    bool cycle = false;
    for (auto el : edgeList)
    {
        long long u = el.first.first;
        long long v = el.first.second;
        long long w = el.second;

        if (dist[u] != INF and dist[u] + w < dist[v])
        {
            cycle = true;
            break;
            dist[v] = dist[u] + w;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int dest;
        cin >> dest;
        if (cycle == false)
        {
            if (dist[dest] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dist[dest] << endl;
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     // cout << "D of " << i << ": " << dist[i] << endl;
    // }
    // cout<<"cycle = "<<cycle<<endl;
    if (cycle)
        cout << "Negative Cycle Detected" << endl;

    return 0;
}