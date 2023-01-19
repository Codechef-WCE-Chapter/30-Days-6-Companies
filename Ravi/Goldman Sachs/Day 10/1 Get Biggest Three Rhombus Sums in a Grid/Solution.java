class Solution {
    
    boolean isPossible(int r, int c, int m, int n) {
        if(r >= 0 && c >= 0 && r < m && c < n) return true;
        return false;
    }
    
    public int[] getBiggestThree(int[][] grid) {
        
        HashSet<Integer> hs = new HashSet<>();
        
        int m = grid.length;
        int n = grid[0].length;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) hs.add(grid[i][j]);
        }
        
        for(int k = 1; k <= 50; k++) {
        
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    
                    if(isPossible(i - k, j, m, n) && isPossible(i, j - k, m, n) && isPossible(i + k, j, m, n) && isPossible(i, j + k, m, n)) {
                        
                        int curr = grid[i - k][j] + grid[i][j - k] + grid[i + k][j] + grid[i][j + k];
                        
                        for(int l = 1; l < k; l++) curr += grid[i - l][j + k - l];
                        for(int l = 1; l < k; l++) curr += grid[i - l][j - k + l];
                        for(int l = 1; l < k; l++) curr += grid[i + l][j + k - l];
                        for(int l = 1; l < k; l++) curr += grid[i + l][j - k + l];
                        
                        hs.add(curr);
                        
                        
                    }
                    
                }
            }
            
        }
        
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(Integer i : hs) arr.add(i);
        
        Collections.sort(arr);
        Collections.reverse(arr);
        
        int[] ans = new int[Math.min(3, arr.size())];
        for(int i = 0; i < Math.min(3, arr.size()); i++) ans[i] = arr.get(i);
        
        return ans;
        
        
    }
    
    
    
}
