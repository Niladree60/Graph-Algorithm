class Solution {
public:


    
    int dfs(vector<vector<int>>& a, int i,int j, int n, int m, int &count)
    {
        if(i < 0 or i >= n  or j < 0 or j >= m or a[i][j] == 0)
        {
            return 0;
        }
        a[i][j] = 0;
        if(dfs(a,i,j+1,n,m,count))
        {
            count++;
        }
        if(dfs(a,i,j-1,n,m,count))
        {
            count++;
        }
        if(dfs(a,i+1,j,n,m,count))
        {
            count++;
        }
        if(dfs(a,i-1,j,n,m,count))
        {
            count++;
        }
        return 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& a) {
            int n = a.size(), m = a[0].size();
            int mx = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m; j++)
            {
                int count = 0;
                if(a[i][j] == 1)
                {
                    count = 1;
                    dfs(a,i,j,n,m,count);
                }
                mx = max(mx,count);
            }
        }
        return mx;
    }
};
