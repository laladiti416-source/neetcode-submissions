class Solution {
public:
    string longestPalindrome(string s) {
        int idx = 0;
        int maxLength = 0;
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--)
        {
            for(int j = i ;j<n;j++)
            {
                if(s[i] == s[j] && ( j-i <=2 || dp[i+1][j-1] ))
                {
                    dp[i][j] = true;
                    int len = j - i + 1;

                    if(len > maxLength)
                    {
                        idx = i;
                        maxLength = len;
                    }
                }
            }
        }
        return s.substr(idx,maxLength);
    }
};
