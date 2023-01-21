class Solution {
    public boolean increasingTriplet(int[] nums) {
        int minm = Integer.MAX_VALUE;
        int sminm = Integer.MAX_VALUE;
        
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > minm) {
                if(nums[i] > sminm) return true;
                sminm = Math.min(sminm, nums[i]);
            } else minm = Math.min(minm, nums[i]);
        }
        return false;
    }
}
