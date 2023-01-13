class Pair {
    long f;
    int s;
    
    Pair(long a, int b) {
        f = a;
        s = b;
    }
}

class Solution {
    public int countPaths(int n, int[][] roads) {
        
        ArrayList<Pair> adj[] = new ArrayList[n];
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        
        for(int[] r : roads) {
            adj[r[0]].add(new Pair(r[1], r[2]));
            adj[r[1]].add(new Pair(r[0], r[2]));
        }
        
        long[] dis = new long[n];
        int[] times = new int[n];
        
        for(int i = 0; i < n; i++) dis[i] = (long)(1e18);
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.f < b.f ? -1 : 1);
        pq.add(new Pair(0l, 0));
        times[0] = 1;
        dis[0] = 0;
        
        while(!pq.isEmpty()) {
            Pair p = pq.poll();
            int node = p.s;
            long w = p.f;
            
            for(Pair i : adj[node]) {
                if(dis[(int)i.f] > (long)(i.s + w)) {
                    dis[(int)i.f] = i.s + w;
                    pq.add(new Pair(dis[(int)i.f], (int)i.f));
                    times[(int)i.f] = times[node];
                } else if(dis[(int)i.f] == (long)(i.s + w)) {
                    times[(int)i.f] = (times[(int)i.f] + times[node]) % ((int)(1e9) + 7);
                }
            }
            
        }
        
        return times[n - 1];
    }
}
