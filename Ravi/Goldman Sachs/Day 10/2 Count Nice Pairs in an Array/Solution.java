class Solution {
    public int countNicePairs(int[] nums) {
        int[] revnums = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++) {
            
            int temp = nums[i];
            
            int curr = 0;
            while(temp > 0) {
                curr = curr * 10 + temp % 10;
                temp /= 10;
            }
            
            revnums[i] = curr;
            
        }
        
        long ans = 0;
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < nums.length; i++) {
            ans += hm.getOrDefault(nums[i] - revnums[i], 0);
            hm.put(nums[i] - revnums[i], hm.getOrDefault(nums[i] - revnums[i], 0) + 1);
        }
        
        long mod = (long)(1e9 + 7);
        return (int)(ans % mod);
        
        
    }
}
