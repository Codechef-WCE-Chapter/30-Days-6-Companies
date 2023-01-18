class Solution {
    
    final long mod = (long)(1e9 + 7);
    
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        
        long[] del = new long[n];
        long[] forg = new long[n];
        
        long curr = 1;
        if(delay < n) del[delay] = 1;
        if(forget < n) forg[forget] = 1;
        
        for(int i = 1; i < n; i++) {
            
            curr = ((curr - forg[i]) % mod + mod) % mod;
            
            del[i] = (del[i] + del[i - 1]) % mod;
            del[i] = ((del[i] - forg[i]) % mod + mod) % mod;
            
            curr = (curr + del[i]) % mod;
            
            if(i + delay < n) del[i + delay] += del[i];
            if(i + forget < n) forg[i + forget] += del[i];
            
        }
        
        int ans = (int)curr;
        return ans;
        
    }
}
