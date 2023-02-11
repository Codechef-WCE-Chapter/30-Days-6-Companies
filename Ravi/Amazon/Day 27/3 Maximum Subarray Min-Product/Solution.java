class Solution {

    public int maxSumMinProduct(int[] nums) {
        Stack<Integer> st = new Stack<>();
        
        long mod = (long)(1e9 + 7);
        
        int n = nums.length;
        
        long maxm = 0;
        
        long prefix[] = new long[n];
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + nums[i];
        
        for(int i = 0; i <= n; i++) {
            while(!st.isEmpty() && (i == n || nums[st.peek()] >= nums[i])) {
                long height = nums[st.pop()];
                long width = 0;
                if(st.isEmpty()) width = prefix[i - 1];
                else width = prefix[i - 1] - prefix[st.peek()];
                maxm = Math.max(maxm, height * width);
            }
            st.push(i);
        }
        
        return (int)(maxm % mod);
    }
}
