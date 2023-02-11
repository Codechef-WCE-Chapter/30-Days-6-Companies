class Solution {
    public int maxSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        
        int ans = 0;
        
        for(int i = 0; i < n - 2; i++) {
            for(int j = 1; j < m - 1; j++) {
                int curr = 0;
                curr += grid[i][j - 1];
                curr += grid[i][j];
                curr += grid[i][j + 1];
                curr += grid[i + 1][j];
                curr += grid[i + 2][j - 1];
                curr += grid[i + 2][j];
                curr += grid[i + 2][j + 1];
                ans = Math.max(ans, curr);
            }
        }
        return ans;
    }
}
