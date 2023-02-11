class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        
        int ans = 0;
        for(int l : left) ans = Math.max(ans, l);
        for(int r : right) ans = Math.max(ans, n - r);
        
        return ans;
        
    }
}
