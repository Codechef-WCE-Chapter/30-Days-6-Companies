class Pair {
    
    int f;
    int s;
    
    Pair(int a, int b) {
        f = a;
        s = b;
    }
    
}
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        
        ArrayList<Pair> adj[] = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++) adj[i] = new ArrayList<>();
        
        for(int[] t : times) {
            adj[t[0]].add(new Pair(t[1], t[2]));
            // adj[t[1]].add(new Pair(t[0], t[2]));
        }
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.f - b.f);
        
        pq.add(new Pair(0, k));
        
        int dis[] = new int[n + 1];
        for(int i = 0; i <= n; i++) dis[i] = (int)(1e9);
        
        dis[k] = 0;
        
        while(!pq.isEmpty()) {
            
            Pair p = pq.poll();
            
            int d = p.f;
            
            int u = p.s;
            
            for(Pair i : adj[u]) {
                
                int v = i.f;
                int w = i.s;
                
                if(dis[v] > d + w) {
                    dis[v] = d + w;
                    pq.add(new Pair(d + w, v));
                }
                
            }
            
        }
        
        int ans = 0;
        
        dis[0] = 0;
        
        for(int i : dis) if(i != 0) ans = Math.max(ans, i);
        
        return ans != (int)(1e9) ? ans : -1;
        
        
    }
}
