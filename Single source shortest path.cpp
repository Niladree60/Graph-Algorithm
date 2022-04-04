#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005], dis[200005];
vector<ll> adj[200005];
// SSSP Algorithm
void dfs(ll node , ll d)
{
  vis[node] = 1;
  dis[node] = d;
  for(int child : adj[node])
  {
    if(vis[child] == 0)
    {
      dfs(child , dis[node] + 1);
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

  ll q, ans = -1 , min_dis = 999999999;
  cin >> q;
  while(q--)
  {
    ll city;
    cin >> city;
    if(dis[city] < min_dis)
    {
      min_dis = dis[city];
      ans = city;
    }
    else if(dis[city] == min_dis and city < ans)
    {
      ans = city;
    }
  }
  cout << ans << endl;

  
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
