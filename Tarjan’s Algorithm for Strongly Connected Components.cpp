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


    vector<ll> adj[1001];
    bool vis[1001],onStack[1001];
    ll in[1001],low[1001];
    stack<ll> st; 
    ll timer = 1, SCC = 0;

    void dfs(ll node)
    {
        vis[node] = 1;
        in[node] = low[node] = timer++;
        onStack[node] = true;
        st.push(node);
        for(int child : adj[node])
        {
            if(vis[child] == true and onStack[child] == true)
            {
                low[node] = min(low[node],in[child]);
            }
            else
            {
                if(vis[child] == false)
                {
                    dfs(child);
                    if(onStack[child] == true)
                    {
                        low[node] = min(low[node],low[child]);
                    }
                }
            }
        }
        
        if(in[node] == low[node])
        {
            SCC++;
            cout << "SCC : " << SCC << endl;
            ll u;
            while(1)
            {
                u = st.top();
                st.pop();
                onStack[u] = false;
                cout << u << " ";
                if(u == node)
                {
                    break;
                }
            }
            cout << endl;
        }

    }

    void solve()
    {
        ll n,m;
        cin >> n >> m;
        for(int i = 1 ; i <= m ; i++)
        {
            ll a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            
        }
        for(int i = 1 ; i <= n ; i++)
        {
            vis[i] = onStack[i] = false;
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(vis[i] == false)
            {
                dfs(i);
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
        solve();
        return 0;
    }
             
