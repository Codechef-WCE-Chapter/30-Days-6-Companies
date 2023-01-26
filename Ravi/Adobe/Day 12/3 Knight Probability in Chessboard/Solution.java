class Solution {
    
    double[][][][] dp;
    
    double[] knight(int i, int j, int k, int n) {
        
        if(i >= n || j >= n || i < 0 || j < 0) return new double[]{0, 1};
        
        if(k == 0) return new double[]{1, 0};
        
        // System.out.println("Wow 2");
        
        if(dp[i][j][k][0] != -1) return dp[i][j][k];
        
        // System.out.println("Wow");
        
        double ans[] = new double[2];
        
        int dir_x[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dir_y[] = {1, -1, 1, -1, 2, -2, 2, -2}; 
        
        for(int l = 0; l < 8; l++) {
            double[] curr = knight(i + dir_x[l], j + dir_y[l], k - 1, n);
            ans[0] += curr[0];
            ans[1] += curr[1];
        }
        
        // System.out.println(i + " " + j + " " + k + " " + ans[0] + " " + ans[1]);
        
        return dp[i][j][k] = ans;
        
    }
    
    public double knightProbability(int n, int k, int row, int column) {
        
        if(k == 0) return 1.0;
        
        
        dp = new double[n][n][k + 1][2];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int l = 0; l <= k; l++) {
                    for(int m = 0; m < 2; m++) dp[i][j][l][m] = -1;
                }
            }
        }
        
        double[] ans = knight(row, column, k, n);
        
        // System.out.println(ans[0] + " " + ans[1]);
        
        double in = ans[0];
        double total = Math.pow(8, k);
        
        return (double)(in * 1.0 / total);
        
    }
}
