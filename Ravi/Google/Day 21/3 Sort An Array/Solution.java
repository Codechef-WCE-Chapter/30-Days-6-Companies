class Solution {
    public int[] sortArray(int[] nums) {
        
        for(int i = 1; i <= nums.length; i++) {
            
            int j = i / 2;
            int k = i;
            while(j > 0) {
                if(nums[k - 1] > nums[j - 1]) {
                    int temp = nums[k - 1];
                    nums[k - 1] = nums[j - 1];
                    nums[j - 1] = temp;
                    
                    k /= 2;
                    j /= 2;
                    
                } else break;
            }
            
        }
        
        int p = nums.length;
        for(int i = 1; i <= nums.length; i++) {
            
            int temp = nums[p - 1];
            nums[p - 1] = nums[0];
            nums[0] = temp;
            
            int j = 1;
            
            int fc = 2;
            int sc = 3;
            
            while(sc < p) {
                if(nums[fc - 1] > nums[sc - 1]) {
                    
                    if(nums[j - 1] < nums[fc - 1]) {
                        int temp2 = nums[j - 1];
                        nums[j - 1] = nums[fc - 1];
                        nums[fc - 1] = temp2;
                    } else break;
                    
                    j = fc;
                    fc = 2 * j;
                    sc = 2 *j + 1;
                    
                } else {
                    if(nums[j - 1] < nums[sc - 1]) {
                        int temp2 = nums[j - 1];
                        nums[j - 1] = nums[sc - 1];
                        nums[sc - 1] = temp2;
                    } else break;
                    
                    j = sc;
                    fc = 2 * j;
                    sc = 2 *j + 1;
                }
            }
            
            if(fc < p && nums[j - 1] < nums[fc - 1]) {
                int temp2 = nums[j - 1];
                nums[j - 1] = nums[fc - 1];
                nums[fc - 1] = temp2;
            }
            
            p--;
            
        }
        
        return nums;
    }
}
