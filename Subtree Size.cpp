#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005], size[200005];
vector<ll> adj[200005];

int dfs(int node)
{
  vis[node] = 1;
  ll sub_size = 1;
  for(int child : adj[node])
  {
    if(vis[child] == 0)
    {
      sub_size += dfs(child);
    } 
  }
  size[node] = sub_size;
  return sub_size;
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
  for(int i = 1 ; i <= n ; i++)
  {
    cout << size[i] << " ";
  }
  cout << endl;
  
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
