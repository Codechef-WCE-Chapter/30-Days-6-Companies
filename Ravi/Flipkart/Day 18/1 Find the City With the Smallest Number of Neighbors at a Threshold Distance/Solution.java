class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        
        int matrix[][] = new int[n][n];
          
          for(int i = 0; i < n; i++) {
              for(int j = 0; j < n; j++) {
                  matrix[i][j] = -1;
              }
          }
          
          for(int i = 0; i < n; i++) matrix[i][i] = 0;
          
          for(int[] e : edges) {
              matrix[e[0]][e[1]] = e[2];
              matrix[e[1]][e[0]] = e[2];
          }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == -1) matrix[i][j] = (int)(1e9);
            }
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][j] > matrix[i][k] + matrix[k][j]) matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
        
        int maxm = n;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && matrix[i][j] <= distanceThreshold) curr++;
            }
            
            if(curr <= maxm) {
                maxm = curr;
                ans = i;
            }
            
        }
        
        return ans;
        
    }
}
