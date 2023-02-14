class Solution {
    
    int[][] dp;
    
    int numberofways(int i, int n, int k) {
        
        if(i == n && k == 0) return 1;
        
        if(k <= 0) return 0;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        int ans = (numberofways(i + 1, n, k - 1) + numberofways(i - 1, n, k - 1)) % (int)(1e9 + 7);
        
        return dp[i][k] = ans;
        
    }
    
    public int numberOfWays(int startPos, int endPos, int k) {
        
        if(endPos - startPos > k) return 0;
        
        if(((endPos - startPos) - k) % 2 != 0) return 0;
        
        dp = new int[4000][k + 1];
        
        for(int i = 0; i < 4000; i++) {
            for(int j = 0; j <= k; j++) dp[i][j] = -1;
        }
        
        return numberofways(startPos + 1000, endPos + 1000, k);
        
        
    }
}
