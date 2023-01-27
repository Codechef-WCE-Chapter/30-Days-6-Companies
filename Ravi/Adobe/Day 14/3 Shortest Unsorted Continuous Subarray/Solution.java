class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] nums2 = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++) nums2[i] = nums[i];
        
        Arrays.sort(nums2);
        
        int s = -1;
        int e = -1;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != nums2[i]) {
                if(s == -1) s = i;
                else e = i;
            }
        }
        
        if(s == -1) return 0;
        return e - s  + 1;
        
    }
}
