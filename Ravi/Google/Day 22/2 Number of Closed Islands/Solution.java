class Solution {
    
    int fill(int[][] g, int i, int j) {
        if(i < 0 || j < 0 || i >= g.length || j >= g[i].length || g[i][j] != 0) return 0;
        return (g[i][j] = 1) + fill(g, i + 1, j) + fill(g, i, j + 1) + fill(g, i - 1, j) + fill(g, i, j - 1);
    }
    
    
    public int closedIsland(int[][] g) {
        
        for(int i = 0; i < g.length; i++) {
            for(int j = 0; j < g[i].length; j++) {
                if(i * j * (i - g.length + 1) * (j - g[i].length + 1) == 0) fill(g, i, j);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < g.length; i++) {
            for(int j = 0; j < g[i].length; ++j) ans += fill(g, i, j) > 0 ? 1 : 0;
        }
        
        return ans;
    }
}
