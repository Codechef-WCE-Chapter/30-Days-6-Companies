class Solution {
    // given condition:
    // for i < j
    // nums1[i] - nums1[j] <= nums2[i] - nums2[j]+diff

    // nums1[i] - nums2[i] <= nums1[j] - nums2[j]+diff
    
    // diff[i] - diff[j] <= diff
    public long numberOfPairs(int[] nums1, int[] nums2, int diff) {
        int n = nums1.length ;
        
        // create the difference array
        int[] arr = new int[n] ;
        
        for(int i = 0; i < n; i++) {
            arr[i] = nums1[i] - nums2[i] ;
        }
          
        long ans = solve(arr, diff) ;
        
        return ans ;  
    }

    public long solve(int[] nums, int diff) {
        long ans = mergeSort(nums, 0, 
                    nums.length - 1, diff
                    ) ;
        return ans ;
    }
    
    
    static long mergeSort(int[] nums, int s, int e, int diff) {
        if (e == s) 
            return 0;
        
        // add ansPairs in left array, right array
        // and pairs amongts the two parts
        // while doing the merge sort operations
        int mid = (s+e)/2 ;
        long lrp = mergeSort(nums, s, mid, diff) ;
        long rrp = mergeSort(nums, mid+1, e, diff) ;
        long irp =  merge(nums, s, mid, e, diff) ;
        
       return lrp + rrp + irp ;
    }
    
    static long merge(int[] nums, int s, int mid, int e, int diff) {
        long cnt = 0 ;
        
        int i = mid , j = e, k = 0 ;
        
        // for every i we are finding number of js
        // which satisy the condition but in
        //  linear time
        while (i >= s) {
            while (j >= mid+1 && 
            nums[i] <= (long)nums[j] + diff
            ) 
                j-- ;
            
            cnt += e - (j) ;
            i-- ;
        }
        
        // do the merging in merge sort
        i = s ; j = mid+1 ;
        
        int temp[] = new int[e-s+1] ;
        
        while (i <= mid && j <= e){
            if (nums[i] < nums[j]) 
                temp[k++] = nums[i++] ;
            else 
                temp[k++] = nums[j++] ;
        }
        
        while (i <= mid) temp[k++] = nums[i++] ;
        
        while (j <= e) temp[k++] = nums[j++] ;
        
        for (int m = 0 ; m < e-s+1 ; m++) {
            nums[m+s] = temp[m] ;
        }

        return cnt ;
    }


}
