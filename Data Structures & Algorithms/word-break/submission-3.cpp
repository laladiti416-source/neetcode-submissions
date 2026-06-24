class Solution {
public:
    bool dfs(int i, string s, vector<string>& wordDict,vector<int>& dp)
    { 
        bool found = false;
        if(i == s.size())
        {
            return true;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        for(string str: wordDict)
        {
            int len = str.size();
            if(i+len <= s.size() && s.substr(i,len) == str)
            {
                if(dfs(i+len,s,wordDict,dp))
                {
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return dfs(0,s,wordDict,dp);
    }
};
