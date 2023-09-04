#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
        int u, v , w;  
    Edge(int u,  int v , int w)
    {
        this->u = u; 
        this->v = v; 
        this->w = w; 
    }

};
int n, m; 
const int N = 1000;
const int INF = 1e9+5;
vector<Edge> listOfEdges;
// vector<int> dist(N,INF);
int dist[N];

void BellmanFord(int src)
{
    for(int i = 0; i<=n; i++)
    {
        dist[i] = INF; 
    }
    dist[src] = 0; 
    for(int i = 1;i<n; i++)
    {
        // for(int j = 0; j<listOfEdges.size(); j++)
        for(Edge ed : listOfEdges)
        {
            // Edge ed = listOfEdges[j];
            // cout<<ed.u<<" "<<ed.v<<": "<<ed.w<<endl;
            int u = ed.u;
            int v = ed.v; 
            int w = ed.w;

            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w; 
            }
            
        }
    }
}

int main()
{
    
    cin >> n >> m; 

      
    for(int i = 1;i<=m; i++)
    {
        int u , v , w ; 
        cin >> u >> v >> w ;

        Edge ed (u,v,w);

        // cout<<ed.u <<","<<ed.v<<","<<ed.w<<endl;
        listOfEdges.push_back(ed);  


    }

    // for(auto el : listOfEdges)
    // {
    //     cout<<el.u<<" "<<el.v<<": "<<el.w<<endl;
    // }
    
    bool cycle = false;
    int src;
    cin >>src; 
    BellmanFord(src);

    for(Edge ed : listOfEdges)
        {
            // Edge ed = listOfEdges[j];
            // cout<<ed.u<<" "<<ed.v<<": "<<ed.w<<endl;
            int u = ed.u;
            int v = ed.v; 
            int w = ed.w;

            if(dist[v] > dist[u]+w)
            {
                cycle = true;
                break;
                dist[v] = dist[u]+w;
                 
            }
            
        }


    for(int i = 1; i<=n; i++)
    {
        cout<<"D of "<<i<<": "<<dist[i]<<endl;
    }

    if(cycle) cout<<"Neg. Weight Cycle Exist"<<endl;
    else cout<<"Ther is no Neg. Weight Cycle"<<endl;


    return 0;
}