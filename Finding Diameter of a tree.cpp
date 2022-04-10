#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005], d1[200005], d2[200005];
vector<ll> adj[200005];
ll timer = 1;
void dfs(int node, int d)
{
  vis[node] = 1;
  d1[node] = d;
  for(int child : adj[node])
  {
    if(vis[child] == 0)
    {
      dfs(child, d1[node]+1);
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
  dfs(1,0);
  ll start = 0;
  ll mx = -1;
  for(int i = 1 ; i <= n ; i++)
  {
    if(d1[i] >= mx)
    {
      mx = d1[i];
      start = i;
    }
  }
  cout << "Start " << start << endl;
  for(int i = 1 ; i <= n ;i++)
  {
    vis[i] = 0;
    d1[i] = 0;
  }
  dfs(start, 0);
  for(int i = 1 ; i <= n ; i++)
  {
    cout << d1[i] << " "; 
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
