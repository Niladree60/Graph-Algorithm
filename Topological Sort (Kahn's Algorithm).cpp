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
vector<ll> vc;
ll in[100];
    

void kahn(int n)
{
    queue<ll> q;
    //priority_queue<int, vector<int> , greater<int> > q;
    for(int i = 1 ; i <= n ; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        // int cur = q.top(); this is for the mean heap
        vc.push_back(cur);
        q.pop();
        for(int node : adj[cur])
        {
            in[node]--;
            if(in[node] == 0)
            {
                q.push(node);
            }
        }
    }

    cout << "Toph Sort " << endl;
    for(int x : vc)
    {
        cout << x << " ";
    }
    cout << endl;

}

void solve()
{
    ll n,m;
    cin >> n >> m;
    while(m--)
    {
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }
    kahn(n);
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
         
