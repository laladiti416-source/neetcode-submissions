class Solution {
public:
    int dpSol(vector<int>& cost, int i, vector<int>& dp)
    {
        int takeOneStep = 0;

        if(i == cost.size()-1)
        {
            return cost[i];
        }
        if(i > cost.size()-1)
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        takeOneStep = dpSol(cost,i+1,dp) + cost[i];

        int takeTwoStep = INT_MAX;

        takeTwoStep = dpSol(cost,i+2,dp) + cost[i];
        return dp[i] = min(takeOneStep,takeTwoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);

        return min(dpSol(cost,0,dp), dpSol(cost,1,dp));
    }
};
