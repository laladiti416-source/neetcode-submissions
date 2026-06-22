class Solution {
public:
    int dpSol(int n, vector<int>& dp)
    {
        int takeOneStep = 0;

        if(n==0)
        {
            return 1;
        }
        if(dp[n] != -1)
        {
            return dp[n];
        }
        takeOneStep = dpSol(n-1,dp);
        int takeTwoStep = 0;
        if(n-2>=0)
        {
            takeTwoStep = dpSol(n-2,dp);
        }
        return dp[n]= takeOneStep + takeTwoStep;

    }
    int climbStairs(int n) {
       vector<int> dp(n + 1, -1);
       return dpSol(n, dp);
    }
};
