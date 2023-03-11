class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        
        int n = dungeon.length;
        int m = dungeon[0].length;
        
        int[][] dp = new int[n + 1][m + 1];
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) dp[i][j] = (int)(1e9);
        }
        
        dp[0][1] = 1;
        dp[1][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int req = Math.min(dp[i][j - 1], dp[i - 1][j]) - dungeon[i - 1][j - 1];
                
                if(req <= 0) dp[i][j] = 1;
                else dp[i][j] = req;
                
            }
        }
        
        return dp[n][m];
    }
}
