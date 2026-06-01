class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int freshCount = 0;
        queue<pair<int,int>> q;

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                if(grid[i][j] == 1)
                {
                    freshCount++;
                }
            }
        }
        
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        int level = 0;
        while(freshCount>0 && !q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto node = q.front();
                int i = node.first; //2,2
                int j = node.second;
                vis[i][j] = 1;
                q.pop();

                for(auto dir: directions)
                {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    
                    if(x >=0 && y>=0 && x<m && y<n && !vis[x][y] && grid[x][y] == 1)
                    {
                        q.push({x,y});
                        freshCount--;
                        grid[x][y] = 2;
                       
                    }
                }
            }
           level+=1;
        }
       return freshCount>0? -1: level;
    }
     
};
