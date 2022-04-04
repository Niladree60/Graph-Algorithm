#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005], col[200005];
vector<ll> adj[200005];

bool dfs(ll node , ll c)
{
  vis[node] = 1;
  col[node] = c;
  for(int child : adj[node])
  {
    if(vis[child] == 0)
    {
      if(dfs(child, c^1) == false)
      {
        return false;
      }
    }
    else if(vis[child] == 1)
    {
      if(col[node] == col[child])
      {
        return false;
      }
    }
  }
  return true;
}

void solve()
{
  ll n;
  cin >> n;
  for(int i = 1 ; i <= n ; i++)
  {
    ll a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bool ok = dfs(1,0);
  if(ok)
  {
    cout << "Bipertite" << endl;
  }
  else cout << "Non Bipertite" << endl;
  
  
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
