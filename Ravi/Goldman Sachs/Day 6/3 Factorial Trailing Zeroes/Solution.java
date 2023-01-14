class Solution {
  
   // We will try to find the number of 5 as the divisors in all the numbers upto N
    public int trailingZeroes(int n) {
        
        int ans = 0;
        
        while(n > 0) {
            n /= 5;
            ans += n;
        }
        
        return ans;
        
    }
}
