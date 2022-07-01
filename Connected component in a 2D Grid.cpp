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
ll a[1002][1002];
// for four neighbours
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};
ll n,m;
// for eight neighbours
ll dx1[] = {-1,0,-1,1,0,1,1,-1};
ll dy1[] = {0,-1,-1,0,1,1,-1,1};

bool isvalid(int x, int y)
{
    if(x < 1 or x > n or y < 1 or y > m or vis[x][y] == 1 or a[x][y] == 0)
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    //for(int i = 0 ;  i< 8 ; i++) // for 8 neighbour
    for(int i = 0 ;  i< 4 ; i++)
    {
        if(isvalid(x+dx[i] , y + dy[i]))
        {
            dfs(x+dx[i] , y + dy[i]);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> a[i][j];
        }
    }
    
    ll cnt = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            if(vis[i][j] == 0 and a[i][j] == 1)
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << "Connected Component : " << cnt << endl;
}
/*
6 6
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0 
0 1 1 0 1 1
*/


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
         
