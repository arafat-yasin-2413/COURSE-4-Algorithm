#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
vector<int>adj[N];
bool visited[N];
vector<int> comp;

void dfs(int src)
{
    visited[src] = true;
    comp.push_back(src); 
    for(int v : adj[src])
    {
        if(visited[v]) continue;
        dfs(v);
    }
}

/*
5 
2
1 2
3 4
*/

int main()
{

/*
    1. নরমালি গ্রাফ ইনপুট নিবো। 
    2. 1 থেকে N পর্যন্ত লুপ চালাবো । প্রত্যেক্টা i ভিজিটেড না হলে তাকে নিয়ে dfs কল করবো। 

    3. যে কয়বার dfs কল করা হবে সেই কয়টা কম্পোনেন্ট আমরা পাবো। 
    
    4. dfs বা bfs কল করা হবে মূলত ভিজিটেড = true করার জন্য। যেমন 1 থেকে 2 এর মধ্যে কোনো কানেকশন আছে। এখন i = 1 যেটা প্রথমে ভিজিটেড থাকবে না। এই 1 কে নিয়ে আমরা dfs কল করতেছি। dfs কল করা হলে 1 এর সাথে কানেক্টেড সকল নোড ই ভিজিট করা হয়ে যাবে। 1 এর dfs শেষ হবার পর যখন ফর লুপের মধ্যে i = 2 হবে তখন আমরা চেক করে দেখতে পাবো যে নোড 2 অলরেডি ভিজিট করা হয়ে গিয়েছে। তাই আমরা এখন i = 2 নিয়ে dfs কল দিবো না। বরং i কে সামনে নিয়ে যাবো । যদি i ভিজিটেড না হয় তখন dfs বা bfs কল দিবো।  
    
    5. আর একবার dfs বা bfs কল হয়ে কম্পোনেন্ট পুশ করার পর কম্পোনেন্ট ভেক্টর টাকে পরবর্তী কলের কম্পোনেন্ট গুলো রাখার জায়গা করে দিতে হবে । অর্থাৎ ক্লিয়ার করে দিতে হবে। 
    

*/



    int n, m; 
    cin >> n >> m ; 
    for(int i = 0; i<m; i++)
    {
        int u , v ; 
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    int cnt = 0; 
    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            cnt++;
            dfs(i);
            
            cout<<"Component "<<i<<" : ";
            for(int el : comp)
            {
                cout<<el<<" ";
            }
            cout<<endl;

            comp.clear(); 
        }
        
    }
    cout<<"Total Component -> "<<cnt<<endl; 

    return 0;
}