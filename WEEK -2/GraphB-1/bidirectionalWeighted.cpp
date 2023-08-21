#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pr;

class Graph
{
    int Vertex;
    list<pr> *adj;

public:
    Graph(int Vertex)
    {
        this->Vertex = Vertex;
        adj = new list<pr>[Vertex];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void printNeigh(int chk)
    {
        cout << "Chk " << chk << ": ";
        for (auto it = adj[chk].begin(); it != adj[chk].end(); it++)
        {
            cout << "(" << (*it).first << "," << (*it).second << ")";
        }
        cout << endl;
    }

    void BFS(int src)
    {
        vector<bool> visited(Vertex, false);
        queue<int> q;
        visited[src] = true;
        // cout<<src<<" ";
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            cout<<u<<" ";
            q.pop();

            for (auto it = adj[u].begin(); it != adj[u].end(); it++)
            {
                int v = (*it).first;
                if (visited[v] == false)
                {
                    visited[v] = true;
                    // cout<<v<<" ";
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }


    void DFS(int src)
    {
        static vector<bool> visited(Vertex,false);
        visited[src] = true;
        cout<<src<<" ";
        for(auto i: adj[src])
        {
            int element = i.first;
            if(visited[element] != true)
            {
                DFS(element);
            }
        }
    }
};

/*
7
10
0
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4 
5 4 6
2 5 8


11
13
0
0 4 6
0 2 5
2 9 1
9 8 3
9 7 4
2 5 3
5 3 6
3 10 2
10 5 1
3 6 7
3 1 4
1 2 5
2 3 8
*/

int main()
{
    int node, edge, source;
    cin >> node >> edge >> source;
    Graph g(node);

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    for (int i = 0; i < node; i++)
    {
        g.printNeigh(i);
    }

    cout<<endl<<endl;

    cout<<"BFS Traversal : "<<endl;
    g.BFS(source);
    cout<<"DFS Traversal : "<<endl;
    g.DFS(source);

    return 0;
}