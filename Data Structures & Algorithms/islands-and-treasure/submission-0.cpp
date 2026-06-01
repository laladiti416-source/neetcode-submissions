class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       queue<pair<int,int>> q;

       for(int i = 0;i<m;i++)
       {
        for(int j = 0;j<n;j++)
        {
            if(grid[i][j] == 0)
            {
                q.push({i,j});
            }
        }
       } 

       vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

       int level = 1;

       while(!q.empty())
       {
          int size = q.size();
          while(size--)
          {
            auto node = q.front();
            int i = node.first;
            int j = node.second;
            q.pop();
            for(auto dir:directions)
            {
                int x = i + dir[0];
                int y = j + dir[1];

                if(x >= 0 && y < n && x<m && y>=0 && grid[x][y] == 2147483647)
                {
                    grid[x][y] = level;
                    q.push({x,y});
                }
            }
          }
          level++;
       }
    }
};
