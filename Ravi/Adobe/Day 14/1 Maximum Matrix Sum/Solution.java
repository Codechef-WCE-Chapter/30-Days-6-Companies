class Solution {
    public long maxMatrixSum(int[][] matrix) {
        
        long ans = 0;
        int minm = Integer.MAX_VALUE;
        int neg = 0;
        
        for(int i = 0; i < matrix.length; i++) {
            for(int j = 0; j < matrix[i].length; j++) {
                if(matrix[i][j] < 0) neg++;
                minm = Math.min(minm, Math.abs(matrix[i][j]));
                ans += Math.abs(matrix[i][j]);
            }
        }
        
        if(neg % 2 != 0) ans -= 2 * minm;
        
        return ans;
        
    }
}
