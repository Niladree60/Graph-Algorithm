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


    vector<ll> adj[100];
    ll in[100],low[100],vis[100];
    ll timer;
    void dfs(int node, int parent)
    {
        vis[node] = 1;
        in[node] = low[node] = timer;
        timer++;

        for(int child : adj[node])
        {
            if(child == parent)
            {
                //do nothing its a direct parent;
                continue;
            }
            if(vis[child] == 1) // this is a back edge
            {
                // node -> child is a Back Edge
                low[node] = min(low[node],in[child]);
            }
            else
            {
                // forward edge
                dfs(child,node);
                low[node] = min(low[node],low[child]);
                if(low[child] > in[node])
                {
                    // its a bridge
                    cout << node << " " << child << " Is a Bridge" << endl;

                    
                }
            }
        }
    }
    /**/
    void solve()
    {
        ll n,m;
        cin >> n >> m;
        while(m--)
        {
            ll x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,-1);
    }



    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        #ifndef ONLINE_JUDGE
        freopen("in.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
        #endif
        solve();

        return 0;
    }
         
