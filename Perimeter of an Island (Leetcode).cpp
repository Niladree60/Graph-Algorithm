class Solution {
public:
    int dir[5] = {0,1,0,-1,0};
    int islandPerimeter(vector<vector<int>>& a) {
        int ans = 0;
        int row = a.size(), col = a[0].size();
        for(int i =0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(a[i][j] == 0)
                {
                    continue;// skip water cell
                }
                ans += 4;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int new_row = i+dir[k];
                    int new_col = j+ dir[k+1];
                    if(new_row < 0 or new_row >= row or new_col < 0 or new_col >= col or a[new_row][new_col] == 0)
                    {
                        continue;
                    }
                    ans--;
                }
            }
        }
        return ans;
        
    }
};
