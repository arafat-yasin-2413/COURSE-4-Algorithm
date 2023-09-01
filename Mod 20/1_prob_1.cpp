#include<bits/stdc++.h>
using namespace std;

//DSU_UNION_BY_SIZE
const int N = 1e5+5;
int parent[N]; 
int parentSize[N]; 

void dsu_set(int n)
{
    for(int i = 1; i<=n; i++)
    {
        parent[i] = i;
        parentSize[i] = 1; 
    }
}

int dsu_find(int node)
{
    while(parent[node] != node)
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
    if(leaderA != leaderB)
    {
        if(parentSize[leaderA] > parentSize[leaderB])
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


int cnt = 0; 
int main()
{
    
    int n , m; 
    cin >> n >> m; 
    dsu_set(n);
    for(int i = 1; i<=m; i++)
    {
        int u, v; 
        cin>> u >> v ;
        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);
        if(leaderA == leaderB)
        cnt++;
        dsu_union(u,v); 
    }

    cout<<cnt<<endl;

    return 0;
}