class Solution {
    
    // We generate an hash for each prefix and sufix in running loop
    // and compare them. If they are equal, prefix and sufix are also
    // equal.
    
    // HashFunction Used here: F(s) = (s[n-1] - 'a')*p^0 + (s[n-2] - 'a')*p^1 + ....
    
    // for prefix, hash = previousHash*p + (s[i] - 'a')
    // for sufix, hash = previousHash + (s[i] - 'a')*(nextpower of p)
     
    public String longestPrefix(String s) {
        int p = 29 ;
        int n = s.length() ;
        int start = 0, end = n-1 ;
        int len = 0 ;
        
        long preHash = 0, sufHash =  0;
        int mod = (int)1e9 + 7 ;
        long pow = 1 ;
        
        while(start < n - 1) {
            preHash = ((preHash*p)%mod + (s.charAt(start) - 'a'))%mod;
            sufHash += ((s.charAt(end) - 'a') * pow )%mod ;
            sufHash %= mod ;
            pow *= p ;
            pow %= mod ;
            start++ ;
            end-- ;
                
            if(preHash == sufHash){
                len = start ;
            }
        }
        
        return s.substring(0, len) ;
    }
}
