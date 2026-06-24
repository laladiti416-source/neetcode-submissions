class Solution {
public:
    int dfs(vector<int>& coins, int amount, int i)
    {
        if (amount == 0)
            return 0;

        if (i == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];

            return INT_MAX;
        }

        int notTake = dfs(coins, amount, i - 1);

        int take = INT_MAX;

        if (amount >= coins[i])
        {
            int res = dfs(coins, amount - coins[i], i);

            if (res != INT_MAX)
                take = res + 1;
        }

        return min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = dfs(coins, amount, coins.size() - 1);

        return (ans == INT_MAX) ? -1 : ans;
    }
};