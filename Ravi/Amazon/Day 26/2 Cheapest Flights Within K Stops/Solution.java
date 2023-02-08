class Pair {
    int f;
    int s;
    
    Pair(int a, int b) {
        f = a;
        s = b;
    }
    
}
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        
        Queue<Pair> q = new ArrayDeque<>();
        
        ArrayList<Pair> adj[] = new ArrayList[n];
        
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        
        for(int[] f : flights) {
            adj[f[0]].add(new Pair(f[1], f[2]));
        }
        
        int vis[] = new int[n];
        
        for(int i = 0; i < n; i++) vis[i] = Integer.MAX_VALUE;
        
        int ans = Integer.MAX_VALUE;
        
        q.add(new Pair(src, 0));
        
        vis[src] = 0;
        
        k += 2;
        
        while(k-- > 0) {
            int size = q.size();
            while(size-- > 0) {
                Pair p = q.poll();
                
                // System.out.println(p.f + " " + adj[p.f].size()); 
                
                if(p.f == dst) ans = Math.min(ans, p.s);
                
                for(Pair r : adj[p.f]) {
                    if(vis[r.f] > r.s + p.s) {
                        q.add(new Pair(r.f, r.s + p.s));
                        vis[r.f] = r.s + p.s;
                    }
                }
                
            }
        }
        
        return ans != Integer.MAX_VALUE ? ans : -1;
        
    }
}
