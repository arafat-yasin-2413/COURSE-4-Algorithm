#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>>
int n, m;
vector<pii> ans;

// DSU_UNION_BY_SIZE
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1;
    }
}

int dsu_find(int node)
{
    while (parent[node] != node)
    {
        node = parent[node];
    }
    return node;
}

// This is union by size
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // Leader is 'A'
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }

        else
        {
            // Leader is 'B'
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

/*
7
11
1 2 5 
1 3 7
3 2 9
3 5 8
5 6 5
3 6 7
2 4 6
2 6 15
4 6 8
4 7 11
6 7 9


output
1 2 5
5 6 5
2 4 6
1 3 7
3 6 7
6 7 9
*/

int main()
{
    cin >> n >> m;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dsu_set(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        pq.push({w, {u, v}});
    }

    // Kruskal's Algorithm
    while (!pq.empty())
    {
        auto el = pq.top();
        pq.pop();

        int w = el.first;
        int u = el.second.first;
        int v = el.second.second;
        // u আর v যদি কোনো সাইকেল form না করে তাহলে তাদেরকে আমরা নিবো।
        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);
        if (leaderU == leaderV)
            continue;
        ans.push_back({w, {u, v}});
        dsu_union(u, v);
    }

    for (auto e : ans)
    {
        cout << e.second.first << " " << e.second.second << " " << e.first << endl;
    }

    return 0;
}