class Solution {

    int []ori;
    int []copy;
    public Solution(int[] nums) {
        copy = nums;
        ori = nums.clone();
    }
    
    public int[] reset() {
        return ori;
    }
    
    public int[] shuffle() {
        Random rand = new Random();
        int n = rand.nextInt(ori.length);
        int t = copy[n];
        copy[n] = copy[0];
        copy[0] = t;
        return copy;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
