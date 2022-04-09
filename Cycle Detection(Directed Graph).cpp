#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005];
vector<ll> adj[200005];

bool dfs(int node)
{
  vis[node] = 1;
  for(int child : adj[node])
  {
    if(vis[child] == 0)
    {
      if(dfs(child) == true)
      {
        return true;
      }
    }
    else
    {
      if(vis[child] == 1)
      {
        return true;
      }
    }
  }
  vis[node] = 2;
  return false;
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
  }
  bool ok = dfs(1);
  if(ok)
  {
    cout << "Found Cycle" << endl;
  }
  else cout <<  "No Cycle" << endl;
  
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
