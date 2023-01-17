class Solution {
public:
long long int mod = (long long int)1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        if(forget<=delay)return 1;
        long long int ans = 0;
        vector<long long int>dp(n+1,0);
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            int d,f;
            if(i-delay<0)d = 0;
            else d = dp[i-delay];
            if(i-forget<0)f = 0;
            else f = dp[i-forget];

            dp[i] = ((ans+d)-f + mod)%mod;
            ans = dp[i];
        }
        ans = 0;
        for(int i = n-forget+1;i<=n;i++){
            ans=(ans+dp[i])%mod;
        }
        return (int)ans;
    };
};