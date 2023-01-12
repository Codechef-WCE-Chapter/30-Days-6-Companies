class Solution {
    
    long merge(int low, int mid, int high, int[] nums, int diff) {
        
        long ans = 0;
        
        int i = mid, j = high, k = 0;
        
        while(i >= low) {
            while(j >= mid + 1 && nums[i] <= (long)nums[j] + diff) j--;
            ans += high - j;
            i--;
        }
        
        i = low; 
        j = mid + 1;
        
        int temp[] = new int[high - low + 1];
        
        while(i <= mid && j <= high) {
            if(nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }
        
        while(i <= mid) temp[k++] = nums[i++];
        
        while(j <= high) temp[k++] = nums[j++];
        
        
        for(int it = 0 ; it < high - low + 1 ; it++) nums[it + low] = temp[it];
        
        return ans;
        
    }
    
    long countInversions(int low, int high, int[] nums, int diff) {
        
        if(low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        long ans = 0;
        
        ans += countInversions(low, mid, nums, diff);
        ans += countInversions(mid + 1, high, nums, diff);
        ans += merge(low, mid, high, nums, diff);
        
        return ans;
        
    }
    
    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        int[] nums = new int[nums1.length];
        
        for(int i = 0; i < nums1.length; i++) nums[i] = nums1[i] - nums2[i];
        
        return countInversions(0, nums.length - 1, nums, diff);
        
    }
}
