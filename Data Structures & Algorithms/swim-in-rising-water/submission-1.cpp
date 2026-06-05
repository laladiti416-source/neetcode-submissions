class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans;
        vector<vector<int>> vis(r,vector<int>(c,0));
        //Djikstra's algorithm 
        //take a set
        set<array<int,3>> input;
        vector<pair<int,int>> directions={
            {0,1} , {1,0}, {-1,0},{0,-1}
        };
        input.insert({grid[0][0],0,0});
        vis[0][0]=1;
        ans = 0;
        while(!input.empty())
        {
            auto [time,row,col] = *input.begin();
            if(row == r-1 && col == c-1) return time;
            input.erase(*input.begin());
            for(auto& dir:directions)
            {
                    int x = row +dir.first;
                    int y = col+dir.second;
                    if(!isValid(x,y,r,c))continue;
                    if(!vis[x][y])
                    {
                        //2
                        int newTime = max(time, grid[x][y]);
                        input.insert({newTime,x,y});
                        vis[x][y] = 1;
                    }
            }
        }
                    return -1;

    }
    bool isValid(int x,int y,int rows, int cols)
    {
        return (x >= 0 && x< rows && y>=0 && y<cols);

    }
};
