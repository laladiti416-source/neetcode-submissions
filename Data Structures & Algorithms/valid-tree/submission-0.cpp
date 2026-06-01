class Solution {
public:
    unordered_set<int> visited;

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    
        if(!dfs(0,-1,adj,n))
        {
            return false;
        }
        return visited.size() == n;
    }
    bool dfs(int src, int par, vector<vector<int>>& edges, int n)
    {
        if(visited.count(src))
        {
            return false;

        }
        visited.insert(src);

        for(auto nei : edges[src])
        {
            if(nei != par)
            {
                if(!dfs(nei,src,edges,n))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
