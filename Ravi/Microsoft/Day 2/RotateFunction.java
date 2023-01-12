class Solution {
    public int maxRotateFunction(int[] nums) {
        
        int sum = 0;
        
        // We will calculate the total sum of elemnets
        for(int i : nums) sum += i;
        
        int n = nums.length;
        
        // We are calulating 0 * nums[0] + 1 * nums[1] + 2 * nums[2] + 3 * nums[3] ........
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (nums[i] * i);
        }
        
        
        int prev = ans;
        // Now the last elemenet which was having a multiplication factor of n - 1 will have a multiplication factor of 0
        // And all other factors will have a multiplication factor icreased by 1
        // So, we are adding the sum of all remaining elements
        // and subtacting the current element with multiplication factor of (n - 1)
        for(int i = n - 1; i > 0; i--) {
            int curr = prev - (nums[i] * (n - 1));
            curr += (sum - nums[i]);
            
            // Now, we need to find the maximum value of the rotation function
            ans = Math.max(ans, curr);
            prev = curr;
        }
        
        return ans;
        
    }
}
