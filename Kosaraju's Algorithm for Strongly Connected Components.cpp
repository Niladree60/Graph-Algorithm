#include <bits/stdc++.h>
#define mod 1000000007 
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
const double pi = acos(-1.0);
template <class T> using Ordered_Set = tree<T, null_type, less<T>,
        rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
                 tree_order_statistics_node_update>
        ordered_multiset;


vector<ll> adj[1001], tr[1001], order, SCC;
ll vis[1001];

void dfs(ll node)
{
    vis[node] = 1;
    for(int child : adj[node])
    {
        if(vis[child] == 0)
        {
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs1(ll node)
{
    vis[node] = 1;
    for(int child : tr[node])
    {
        if(vis[child] == 0)
        {
            dfs1(child);
        }
    }
    SCC.push_back(node);
}

void solve()
{
    ll n,m;
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        tr[i].clear();
        vis[i] = 0;
    }
    order.clear();
    for(int i = 1 ; i <= m ; i++)
    {
        ll a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        tr[b].push_back(a);
    }
    // generating the list of nodes by orders
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i] == 0)
        {
            dfs(i);
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        vis[i] = 0;
    }
    // run DFS on transpose graph
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[order[n-i]] == 0)
        {
            SCC.clear();
            dfs1(order[n-i]);
            cout << "dfs1 called from " << order[n-i] << " and printing SCC " << endl;
            for(int node : SCC)
            {
                cout << node <<  " ";
            }
            cout << endl;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
    ll tc;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    

    return 0;
}
         
