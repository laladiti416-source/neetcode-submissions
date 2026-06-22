class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+2,-1);
        dp[n] = nums[n];
        dp[n+1] = 0;
        for(int i=n-1;i>=0;i--)
        {
            dp[i] = max((nums[i] + dp[i+2]),dp[i+1]);
        }
        return dp[0];
    }
};
