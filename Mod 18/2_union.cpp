#include<bits/stdc++.h>
using namespace std;

int parent[1000];

void initialize(int n)
{
    for(int i = 1; i<=n; i++)
    {
        parent[i] = i;
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

void dsu_union(int a, int b)
{
    int leaderA= dsu_find(a);
    int leaderB= dsu_find(b); 
    if(leaderA!=leaderB)
    {
        parent[leaderB] = leaderA;
        
    }

}

int main()
{
    int n ,m; 
    cin >>n>>m; 

    initialize(n);
    for(int i = 1;i<=m; i++)
    {
        int a, b; 
        cin >> a >> b; 
        dsu_union(a,b);

    }

    for(int i = 1;i<=n;i++)
    {
        cout<<parent[i]<<" "; 
    }    

    return 0;
}