class Solution {
    public int maxConsecutive(int bottom, int top, int[] special) {
        int ans = 0;
        
        Arrays.sort(special);
        
        for(int i : special) {
            ans = Math.max(ans, i - bottom);
            bottom = i + 1;
        }
        
        ans = Math.max(ans, top - special[special.length - 1]);
        
        return ans;
        
    }
}
