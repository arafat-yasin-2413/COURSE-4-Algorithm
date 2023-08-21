#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 1e3+9;
vector<string> g;
int visited[N][N];
int level[N][N];
pii parent[N][N];
int n, m; 
vector<pii> direc={{0,-1},{0,1},{-1,0},{1,0}};


bool isValid(int i, int j )
{
    return (i>=0 && i<n && j>=0 && j<m);
}


void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si,sj});
    visited[si][sj] = true;
    level[si][sj] = 0; 

    while(!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;

        q.pop();

        for (auto d : direc)
        {
            int ni = i+d.first;
            int nj = j+d.second;

            if(isValid(ni,nj) && !visited[ni][nj] && g[ni][nj]!='#')
            {
                q.push({ni,nj});
                visited[ni][nj] = true;
                level[ni][nj]= level[i][j]+1;
                parent[ni][nj] = {i,j};
            }
        }
    }

}



int main()
{
    int n, m; 
    cin >> n >> m;
    int si, sj, di, dj;
    for(int i = 0;i<n; i++)
    {
        string x; 
        cin >> x; 
        for(int j = 0; j<m; j++)
        {
            if(x[j] == 'A')
                si = i, sj = j;
            if(x[j] == 'B')
                di =i, dj = j;
        }
        g.push_back(x);
    }

    bfs(si,sj);
    // cout<<level[di][dj] <<endl;
    
    if(level[di][dj] != 0)
    {
        cout<<"YES"<<endl;
        cout<<level[di][dj]<<endl;
    }
    else 
        cout<<"NO"<<endl;

    vector<pii> path;
    pii curr = {di,dj};

    while(!(curr.first == si && curr.second== sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }

    for(auto p : path)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }
    

    return 0;
}