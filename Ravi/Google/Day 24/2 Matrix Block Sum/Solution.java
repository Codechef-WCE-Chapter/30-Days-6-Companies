class Solution {
    public int[][] matrixBlockSum(int[][] mat, int k) {
        
        int n = mat.length;
        int m = mat[0].length;
        
        int[][] ans = new int[n][m];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                for(int l = Math.max(0, i - k); l <= Math.min(n - 1, i + k); l++) {
                    
                    for(int o = Math.max(0, j - k); o <= Math.min(m - 1, j + k); o++) {
                        ans[i][j] += mat[l][o];
                    }
                    
                }
                
            }
        }
            
        return ans;
        
    }
}
