class Solution 
{
    public List<Integer> largestDivisibleSubset(int[] nums) 
    {
        int n = nums.length ;
        
        int[] hash = new int[n] ;
        
        int[] dp = new int[n] ;
        
        Arrays.sort(nums) ;
        int lastIndex = 0;
        int maxLen = 0 ;
        
        for (int ind = 0 ; ind < n; ind++)
        {
            dp[ind] = 1 ;
            hash[ind] = ind ;
            for (int prev = 0 ; prev < ind; prev++)
            {
                if (nums[ind] % nums[prev] == 0 && dp[ind] < dp[prev] + 1)
                {
                    dp[ind] = dp[prev] + 1 ;
                    hash[ind] = prev ;
                }
            }
            
            if (dp[ind] > maxLen)
            {
                maxLen = dp[ind] ;
                lastIndex = ind ;
            }
            
        }
        
        LinkedList<Integer> ans = new LinkedList<>() ;
        
        ans.addFirst(nums[lastIndex]) ;
        
        while (lastIndex != hash[lastIndex])
        {
            lastIndex = hash[lastIndex] ;
            ans.addFirst(nums[lastIndex]) ;
        }
        
        return ans ;
        
    }
}
