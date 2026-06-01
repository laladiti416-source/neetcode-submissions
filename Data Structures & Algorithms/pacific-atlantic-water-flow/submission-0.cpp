class Solution {
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pac(rows,vector<int>(cols,0));
        vector<vector<int>> atl(rows,vector<int>(cols,0));
        queue<pair<int,int>> pacQueue;
        queue<pair<int,int>> atlQueue;
        for(int i=0;i<rows;i++)
        {
            pacQueue.push({i,0});
            atlQueue.push({i,cols-1});
        }
        for(int i=0;i<cols;i++)
        {
            pacQueue.push({0,i});
            atlQueue.push({rows-1,i});
        }
        bfs(pacQueue,pac,heights);
        bfs(atlQueue,atl,heights);

        for(int i=0;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                if(pac[i][j] == 1 && atl[i][j] == 1)
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& ocean,vector<vector<int>>& heights)
    {
        
        
        while(!q.empty())
        {
           auto [r,c] = q.front();
           q.pop(); 
            ocean[r][c] = 1;
            for(auto [dr,dc] : directions)
            {
                int nr = r + dr;
                int nc = c + dc;
                if(nr >= 0 && nc >=0 && nr<heights.size() && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c])
                {
                    q.push({nr,nc});
                }
            }
        }
    }
};
