class Solution {
    int INF = INT_MAX;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> dist(n+1,INF);

        set<pair<int,int>> s;
        s.insert({0,k});
        dist[k]=0;
        while(!s.empty())
        {
            auto node = *s.begin();
            s.erase(*s.begin());
            if(node.first > dist[node.second])
            {
                continue;
            }
            for(auto neigh : graph[node.second])
            {
               int ne = neigh.first;
                int wt = neigh.second;

                if(dist[ne] > dist[node.second]+ wt)
                {
                    dist[ne] = dist[node.second]+ wt;
                    s.insert({dist[ne],ne});
                }
            }
        }
        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            if(dist[i] == INF)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
