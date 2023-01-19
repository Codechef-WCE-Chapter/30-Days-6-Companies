class Solution {
    public int countNicePairs(int[] nums) {
        int n = nums.length ;
        int[] arr = new int[n] ;
        int mod = (int)1e9+7 ;
        
        long ans = 0 ;
        HashMap<Long, Long> map = new HashMap<>() ;
        for(int i = 0; i < n; i++){
            int num = nums[i] ;
            int temp = num ;
            int rev = 0 ;
            while(temp > 0) {
                rev *= 10 ;
                rev += temp%10 ;
                temp /= 10 ;
            }
        
            int x = num - rev ;
            ans += map.getOrDefault(x*1L, 0L) ;
            ans %= mod ;
            map.put(x*1L, map.getOrDefault(x*1L, 0L)+1) ;
        }
        
        return (int)ans ;
    }
}
