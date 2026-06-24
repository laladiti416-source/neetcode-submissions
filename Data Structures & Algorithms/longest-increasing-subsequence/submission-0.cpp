class Solution {
private:
    vector<int> memo;

    int dfs(vector<int>& nums, int i) {
        if (memo[i] != -1) {
            return memo[i];
        }

        int LIS = 1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j]) {
                LIS = max(LIS, 1 + dfs(nums, j));
            }
        }

        return memo[i] = LIS;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n, -1);

        int maxLIS = 1;
        for (int i = 0; i < n; i++) {
            maxLIS = max(maxLIS, dfs(nums, i));
        }
        return maxLIS;
    }
};