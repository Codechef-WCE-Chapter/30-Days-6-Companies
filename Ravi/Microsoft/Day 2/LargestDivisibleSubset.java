class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        
        // Dp array will store the number of factors before this elements
        int []dp = new int[nums.length];
        
        // It will store the parent of current element i.e previous factor
        int []prev = new int[nums.length];
        
        for(int i = 0; i < nums.length; i++) prev[i] = i;
        
        for(int i = 0; i < nums.length; i++) dp[i] = 1;
        
        // So, we will traverse from 0 to i and check which is the element having maximum number of divisors and divisible by current element and store it as the parent
        for(int i = 0; i < nums.length; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] >= dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        
        // Finding the element with maximum number of divisors
        int maxi = 0;
        for(int i = 0; i < nums.length; i++) {
            if(dp[i] > dp[maxi]) maxi = i;
            System.out.print(dp[i] + " ");
        }
        
        // Traversing back with the parent array
        List<Integer> ans = new ArrayList<>();
        while(prev[maxi] != maxi) {
            ans.add(nums[maxi]);
            maxi = prev[maxi];
        }
        ans.add(nums[maxi]);
        return ans;
        
    }
}
