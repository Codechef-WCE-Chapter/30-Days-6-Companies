class Solution {
    public int[] getBiggestThree(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int maxLen = (int)Math.ceil(Math.min(m, n)*1.0/2);
        TreeSet<Integer> ans = new TreeSet<Integer>((x, y) -> y - x);
        
        for(int len = 0; len < maxLen; len++) { 
            for(int i = 0; i < m - 2*len; i++) {
                for(int j = 0 + len; j < n - len; j++) {
                    int cur = grid[i][j];
                    for(int k = 1; k < 2*len; k++) {
                        if(k <= len) {
                            cur += grid[i+k][j-k] + grid[i+k][j+k];
                        } else {
                            cur += grid[i+k][j-(2*len-k)] + grid[i+k][j+(2*len-k)];
                        }
                    }
                    
                    if(len != 0){
                        cur += grid[i+2*len][j] ;
                    }
                    
                    ans.add(cur);
                    if(ans.size() > 3)
                        ans.pollLast();
                }
            }
        }
        
        int[] ansArr = new int[ans.size()] ;
        for(int i = 0; i < ansArr.length; i++) {
            ansArr[i] = ans.pollFirst() ;
        }
        
        return ansArr ;
    }
}
