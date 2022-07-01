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


ll vis[1002][1002];
ll dis[1002][1002];
// for four neighbours
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};
ll n,m;
// for eight neighbours
ll dx1[] = {-1,0,-1,1,0,1,1,-1};
ll dy1[] = {0,-1,-1,0,1,1,-1,1};

bool isvalid(int x, int y)
{
    if(x < 1 or x > n or y < 1 or y > m or vis[x][y] == 1 )
    {
        return false;
    }
    return true;
}

void bfs(int srcX, int srcY)
{
    queue< pair<ll,ll> > q;
    q.push({srcX,srcY});
    vis[srcX][srcY] = 1;
    dis[srcX][srcY] = 0;
    while(!q.empty())
    {
        ll curX = q.front().first;
        ll curY = q.front().second;
        q.pop();
        for(int i  =0 ;  i< 4 ; i++)
        {
            if(isvalid(curX+dx[i] , curY + dy[i]))
            {
                ll newX = curX+dx[i];
                ll newY = curY+dy[i];
                q.push({newX,newY});
                vis[newX][newY] = 1;
                dis[newX][newY] = dis[curX][curY] +1;
            }
        }
    }

    cout << "Distance Array " << endl;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cout << dis[i][j]  << " ";
        }
        cout << endl;
    }
}

void solve()
{
    cin >> n >> m;
    ll x,y;
    cin >> x >> y;
    bfs(x,y);
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
         
