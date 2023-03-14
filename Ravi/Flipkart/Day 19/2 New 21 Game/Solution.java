class Solution {
    public double new21Game(int n, int k, int maxPts) {
        
        if(k == 0 || n >= k + maxPts) return 1;
        
        int pp = k + maxPts - 1;
        
        double[] dp = new double[n + 1];
        dp[0] = 1;
        
        double psum = 1;
        double ans = 0;
        
        for(int i = 1; i <= n; i++) {
            dp[i] = psum * 1.0 / maxPts;
            if(i < k) psum += dp[i];
            else ans += dp[i];
            
            if(i - maxPts >= 0) psum -= dp[i - maxPts];
            
        }
        
        return ans;
        
    }
}
