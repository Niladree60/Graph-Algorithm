#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005];
vector<ll> adj[200005];

void dfs(ll v)
{
  vis[v] = 1;
  cout << v << " ";
  for(int child : adj[v])
  {
    if(vis[child] == 0)
    {
      dfs(child);
    }
  }
}

void solve()
{
  ll n;
  cin >> n;
  for(int i = 1 ; i <= n-1 ; i++)
  {
    ll a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
    freopen("ou.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
