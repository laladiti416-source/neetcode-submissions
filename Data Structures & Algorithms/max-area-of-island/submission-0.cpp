class Solution {
public:
    vector<vector<int>> vis;

    vector<pair<int,int>> directions = {
        {-1,0},{0,-1},{1,0},{0,1}
    };

    bool isValid(int i, int j, vector<vector<int>>& grid)
    {
        return i >= 0 &&
               i < grid.size() &&
               j >= 0 &&
               j < grid[0].size() &&
               grid[i][j] == 1;
    }

    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        vis[i][j] = 1;
        int ans = 1;

        for(auto direction : directions)
        {
            int x = i + direction.first;
            int y = j + direction.second;

            if(isValid(x,y,grid) && !vis[x][y])
            {
                ans += dfs(grid,x,y);
            }
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<int>(n, 0));

        int area = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isValid(i,j,grid) && !vis[i][j])
                {
                    area = max(area, dfs(grid,i,j));
                }
            }
        }

        return area;
    }
};