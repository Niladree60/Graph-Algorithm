#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005], in[200005], out[200005];
vector<ll> adj[200005];
ll timer = 1;
void dfs(int node)
{
  vis[node] = 1;
  in[node] = timer;
  timer++;
  for(int child : adj[node])
  {
    if(vis[child] == 0)
    {
      dfs(child);
    }
    
  }
  out[node] = timer;
  timer++;
}
// if a node y lies in the subtree of node x then in[x] < in[y] and out[x] > out[y] 
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
  dfs(1);

  for(int i = 1 ; i <= n ; i++)
    cout << in[i] << " ";
  cout << endl;
  for(int i = 1 ; i <= n ; i++)
    cout << out[i] << " ";
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
