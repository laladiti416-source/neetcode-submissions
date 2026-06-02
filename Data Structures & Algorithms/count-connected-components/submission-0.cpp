class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int scc = 0;
        vector<int> visited(n,0);
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(graph,visited,i,-1);
                scc++;
            }
        }
        return scc;
    }
    void dfs(unordered_map<int,vector<int>>& graph,vector<int>& visited, int src, int par)
    {
        visited[src]=1;

        for(auto neigh: graph[src])
        {
            if(neigh == par) continue;
            if(!visited[neigh])
            {
            dfs(graph,visited,neigh,src);
            }
        }
    }
};
