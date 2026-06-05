class Solution {
    unordered_map<string, multiset<string>> graph;
    vector<string> answer;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto &tic:tickets)
        {
            graph[tic[0]].insert(tic[1]);
        }

        dfs("JFK");

        reverse(answer.begin(),answer.end());

        return answer;
    }
    void dfs(string airport)
    {
        while(!graph[airport].empty())
        {
        auto neigh = graph[airport].begin();
        string ne = *neigh;
        graph[airport].erase(neigh);
        dfs(ne);
        }
        answer.push_back(airport);
    }
};
