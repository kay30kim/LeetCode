class Solution {
public:
    // s = abc p = b*c
    // s = abc p = *
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        
        // dp[n][m] means string s and string p are same until index 0 to index n and index 0 to index m
        dp[0][0] = true;
        for(int i=0; i<m; i++){
            if(p[i]=='*' && dp[0][i] == true){
                dp[0][i+1] = true;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(p[j]=='?' || p[j] ==s[i]){
                    dp[i+1][j+1] = dp[i][j] & true;
                }else if(p[j]=='*'){
                    dp[i+1][j+1] = dp[i][j] & true;
                    if(dp[i+1][j+1] == false) dp[i+1][j+1] = dp[i][j+1] & true;
                    if(dp[i+1][j] == true) dp[i+1][j+1] = true;
                }
            }
        }
        
        return dp[n][m];
    }
};