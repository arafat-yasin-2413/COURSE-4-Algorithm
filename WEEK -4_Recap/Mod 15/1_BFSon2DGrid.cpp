#include <bits/stdc++.h>
using namespace std;



const int N = 1e3 + 7;

bool visited[N][N];
int dist[N][N];
vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;


bool isValid(int ci, int cj)
{
    if (ci >= 0 and ci < n and cj >= 0 and cj < m)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    // 1. কিউ তে সোর্স পুশ করি।
    queue<pair<int, int>> q;
    q.push({si, sj});

    // 2. src সেল (si,sj) এর ভিজিটেড ট্রু করি।
    visited[si][sj] = true;

    // 3. src এর (si,sj) distance 'zero' সেট করি। বাকি সব সেলের distance initially 'zero' ই থাকবে।
    dist[si][sj] = 0;

    // 4. কিউ খালি না হওয়া পর্যন্ত একটা করে সেল বের করে তার চিল্ড্রেন সেল গুলো বের করি।
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;

        for (int i = 0; i < path.size(); i++)
        {

            int ci = pi + path[i].first;
            int cj = pj + path[i].second;

            if (isValid(ci, cj) and !visited[ci][cj])
            {
                visited[ci][cj] = true;
                dist[ci][cj] = dist[pi][pj] + 1;
                q.push({ci, cj});
            }
        }
    }

    // 5. চিল্ড্রেন সেল গুলো ভ্যালিড কিনা চেক করি।

    // 6. চিল্ড্রেন সেল গুলো ভিজিটেড=false হলে ->  ভিজিট করি, dist আপডেট করি, কিউ তে পুশ করি
}

int main()
{

    cin >> n >> m;
    char ar[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
        }
    }

    // for(int i = 0; i<n; i++)
    // {
    //     for(int j = 0; j<m; j++)
    //     {
    //         cout<< ar[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int si, sj;
    cin >> si >> sj;

    bfs(si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
// #define pi pair<int,int>
vector<pair<int,int>> path ={{-1,0},{1,0},{0,-1},{0,1}};
const int N = 1e3+5;
bool visited[N][N];
int dist[N][N];
int n, m;

bool isValid(int ci, int cj)
{
    if(ci>=0 and ci<n and cj>=0 and cj<m)
    return true;
    else return false;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    dist[si][sj] = 0;
    visited[si][sj] = true;

    while(!q.empty())
    {
        pair<int,int> parent = q.front();
        int pi = parent.first;
        int pj = parent.second;
        q.pop();

        // children 4 ta (left,right,up,down)
        for(int i = 0; i<m; i++)
        {
            // ekta ekta kore path ber kori
            pair<int,int> p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second;
            // ekhon dekhbo j children er i-th and j-th index valid kina
            // index er validity agee check korte hobe
            // tarpor visited a oi cell ta k true kore dite hobe

            // cout<<ci<<" "<<cj<<endl;
            if(isValid(ci,cj) and !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci,cj});
                dist[ci][cj] = dist[pi][pj] + 1;
            }
        }
    }
}


int main()
{

    cin >> n >> m;

    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << a[i][j];
    //     }
    //     cout<<endl;
    // }

    int si, sj;
    cin >> si >> sj;

    bfs(si,sj);

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            // cout<<dist[i][j]<<" ";
            cout<<"dist["<<i<<"]["<<j<<"] : "<<dist[i][j]<<endl;
        }
        // cout<<endl;
    }


    return 0;
}
*/