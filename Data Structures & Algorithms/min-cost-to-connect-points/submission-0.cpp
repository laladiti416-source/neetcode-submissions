class DSU{
    public:
    vector<int> parent,Size;
    DSU(int n): parent(n+1),Size(n+1,1){
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int find(int v)
    {
        if(parent[v] != v)
        {
            parent[v]=find(parent[v]);
            
        }
        return parent[v];
    }

    bool unionSets(int u,int v)
    {
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)
        {
            return false;
        }
        if(Size[pu] < Size[pv])
        {
            swap(pu,pv);
            
        }
        parent[pv] = pu;
        Size[pu]+=Size[pv];
        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<array<int,3>> edges;
        DSU dsu(n);
        for(int i = 0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

                edges.push_back({dist,i,j});
            }
        }
        sort(edges.begin(),edges.end());
        int res = 0;
        for(auto& [dist,u,v]:edges)
        {
                if(dsu.unionSets(u,v))
                {
                    res += dist;
                }
        }
        return res;
    }
};
