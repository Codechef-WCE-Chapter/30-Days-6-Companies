class Solution {
    
    HashMap<String, Boolean> hm = new HashMap<>();
    
    boolean canpartition(int i, int[] nums, int[] sum, int target, int k) {
        
        if(i == nums.length) return true;
        
        StringBuilder sb = new StringBuilder("");
        
        sb.append(i);
        sb.append(" ");
        
        for(int it : sum) {
            sb.append(it);
            sb.append(" ");
        }
        
        // System.out.println(sb.toString());
        
        if(hm.containsKey(sb.toString())) {
            // System.out.println("Hua");
            return hm.get(sb.toString());
        }
        
        boolean f = true;
        
        for(int j = 0; j < k; j++) {
            if(sum[j] + nums[i] <= target) {
                
                if(sum[j] == 0 && f == false) continue;
                
                sum[j] += nums[i];
                if(canpartition(i + 1, nums, sum, target, k)) {
                    hm.put(sb.toString(), true);
                    return true;
                }
                sum[j] -= nums[i];
                
                if(sum[j] == 0) f = false;
                
            }
        }
        
        hm.put(sb.toString(), false);
        return false;
        
    }
    
    public boolean canPartitionKSubsets(int[] nums, int k) {
        
        int curr = 0;
        
        for(int i = 0; i < nums.length; i++) curr += nums[i];
        
        if(curr % k != 0) return false;
        
        int target = curr / k;
        
        int sum[] = new int[k];
        
        Arrays.sort(nums);
        
        int i = 0;
        int j = nums.length - 1;
        
        while(i <= j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        
        if(nums[0] > target) return false;
        
        return canpartition(0, nums, sum, target, k);
        
    }
}
