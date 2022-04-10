#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll vis[200005], dis[200005];
vector<ll> adj[200005];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  vis[src] = 1;
  dis[src] = 0;
  while(!q.empty())
  {
    int v = q.front();
    q.pop();
    for(int child : adj[v])
    {
      if(vis[child] == 0)
      {
        q.push(child);
        dis[child] = dis[v] +1;
        vis[child] = 1;
      }
    }
  }
}


void solve()
{
  ll n,m;
  cin >> n >> m; 
  for(int i = 1 ; i <= n ; i++)
  {
    dis[i] = vis[i] = 0;
  }
  for(int i = 1 ; i <= m ; i++)
  {
    ll a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  bfs(1);
  cout << dis[n] << endl;
  
}

int main() 
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
    freopen("ou.txt" , "w" , stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll tc;
    cin >> tc;
    while(tc--)
    {
      solve();
    }
    
    return 0;
}
