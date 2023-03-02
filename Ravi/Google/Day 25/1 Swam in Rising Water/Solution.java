class Triplet {
    int f;
    int s;
    int t;
    
    Triplet(int a, int b, int c) {
        f = a;
        s = b;
        t = c;
    }
}

class Solution {
    
    public int swimInWater(int[][] grid) {
        PriorityQueue<Triplet> pq = new PriorityQueue<>((a, b) -> a.f - b.f);
        
        pq.add(new Triplet(grid[0][0], 0, 0));
        
        int n = grid.length;
        int m = grid[0].length;
        
        int[][] dis = new int[n][m];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) dis[i][j] = Integer.MAX_VALUE;
        }
        
        dis[0][0] = grid[0][0];
        
        int[] xx = {-1, 1, 0, 0};
        int[] yy = {0, 0, -1, 1};
        
        while(!pq.isEmpty()) {
            
            Triplet tt = pq.poll();
            int t = tt.f;
            int x = tt.s;
            int y = tt.t;
            
            // System.out.println(t + " " + x + " " + y);
            
            if(x == n - 1 && y == m - 1) return t;
            
            for(int i = 0; i < 4; i++) {
                
                int x1 = x + xx[i];
                int y1 = y + yy[i];
                
                if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && dis[x1][y1] > Math.max(t, grid[x1][y1])) {
                    dis[x1][y1] = Math.max(t, grid[x1][y1]);
                    pq.add(new Triplet(dis[x1][y1], x1, y1));
                    
                    // System.out.println(dis[x1][y1] + " " + x1 + " " + y1);
                    
                }
            }
            
        }
        
        return -1;
        
    }
}
