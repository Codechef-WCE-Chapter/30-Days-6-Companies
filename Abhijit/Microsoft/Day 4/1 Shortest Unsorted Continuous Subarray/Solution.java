class Solution {
    
    // Find the smallest and largest out of order element
    // Find their positions in array. ==> If we sort array 
    // between these two positions, whole array is sorted
    public int findUnsortedSubarray(int[] nums) {
        
        int smallest = Integer.MAX_VALUE , largest = Integer.MIN_VALUE ;
        
        int n = nums.length ;
        
        for (int i = 0; i < n ; i++) {
            if (isOutOfOrder(nums, i)) {
                smallest = Math.min(smallest, nums[i]) ;
                largest = Math.max(largest, nums[i]) ;
            }
        }
        
        if (smallest == Integer.MAX_VALUE) return 0 ;
        
        int start = 0 , end = n-1;
        
        while (start < n && nums[start] <= smallest) start++ ;
        
        while (end > 0 && nums[end] >= largest) end-- ;
        
        return end - start + 1 ;
        
    }
    
     static boolean isOutOfOrder(int nums[], int i) {
        
        if (nums.length <= 1) return false ;
        
        if (i == 0) return nums[i] > nums[i+1] ;
        
        if (i == nums.length-1) return nums[i] < nums[i-1] ;
        
        return nums[i] > nums[i+1] || nums[i] < nums[i-1] ;
    }
    
}




