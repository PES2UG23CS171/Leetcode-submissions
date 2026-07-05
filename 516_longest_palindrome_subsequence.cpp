class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0; i<n; i++) {
            dp[i][i]=1;
        }
        for(int i=1; i<n; i++) {
            int r=0, c=i;
            while(c<n) {
                if(s[r]==s[c]) 
                    dp[r][c]=2+dp[r+1][c-1];
                else
                    dp[r][c]=max(dp[r+1][c], dp[r][c-1]);
                r++;
                c++;
            }
        }
        return dp[0][n-1];
    }
};
