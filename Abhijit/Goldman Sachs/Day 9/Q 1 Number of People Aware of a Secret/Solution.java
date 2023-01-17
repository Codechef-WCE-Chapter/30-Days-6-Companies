class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        long dp[] = new long[n + 1];
        long mod  = (long)1e9 + 7;
        long peopleSharingSecret = 0;
        long ans = 0;

        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            long shareNum = dp[Math.max(i - delay , 0)];
            long forgetNum = dp[Math.max(i - forget , 0)];
            peopleSharingSecret += (shareNum - forgetNum + mod) % mod;

            dp[i] = peopleSharingSecret;
        }
        
        for(int i = n - forget + 1 ; i <= n; i++){
            ans = (ans + dp[i]) % mod;
        }
        return (int)ans;
    }
}
