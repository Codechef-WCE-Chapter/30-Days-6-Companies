class Solution {
    /* 
        array = {a, b, c, d, e}
        F(0) = 0*a + b + 2*c + 3*d + 4*e
        F(1) = 0*e + a + 2*b + 3*c + 4*d
        F(2) = 0*d + e + 2*a + 3*b + 4*c

        F(1) - F(0) = a + b + c + d - 4*e
        F(2) - F(1) = e + a + b + c - 4*d

        F(k) = F(k-1) + sum - n*nums[n-k]
     */

    public int maxRotateFunction(int[] nums) {
        int n = nums.length ;
        int sum = 0 ;
        int ans = 0 ;
        for(int i = 0; i < n; i++) {
            ans += i*nums[i] ;
            sum += nums[i] ;
        }
        int maxAns = ans ;

        for(int i = n-1; i >= 0; i--) {
            ans += sum - n*nums[i] ;
            maxAns = Math.max(maxAns, ans) ;
        }

        return maxAns ;
    }
}


