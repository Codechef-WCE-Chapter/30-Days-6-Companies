class Solution {
    
    // Dijkstra algorithm is used, where an extra array is used
    // which tells number of ways to reach a node in cur_min_dist
    
    public int countPaths(int n, int[][] roads) {
        
        int mod = (int) 1e9+7 ;
        
        // creating the graph
        ArrayList<Pair>[] adj = new ArrayList[n] ;
        
        for(int i = 0; i <n; i++){
            adj[i] = new ArrayList<>() ;
        }
        
        for(int[] edge: roads){
            adj[edge[0]].add(new Pair(edge[1], edge[2])) ;
            adj[edge[1]].add(new Pair(edge[0], edge[2])) ;
        }
        
        int[] dist = new int[n] ;
        int[] ways = new int[n] ;
        
        Arrays.fill(dist, Integer.MAX_VALUE) ;
        dist[0] =  0;
        ways[0] = 1 ;
        
        // priority queue which will pop node with smallest dist first
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[1] - b[1] ;
        });
        
        pq.add(new int[]{0, 0}) ;
        
        while(!pq.isEmpty()) {
            int[] top = pq.poll() ;
            
            // check for all neihbours of currently popped node
            // and update dist as well as ways for the nbr if possible
            for(Pair nbr: adj[top[0]]) {
                if(dist[nbr.node] == top[1] + nbr.wt) {
                    ways[nbr.node] += ways[top[0]] ;
                    ways[nbr.node] %= mod;
                }
                else
                if(dist[nbr.node] > top[1] + nbr.wt) {
                    dist[nbr.node] = top[1] +  nbr.wt ;
                    ways[nbr.node] = ways[top[0]] ;
                    pq.add(new int[]{nbr.node, dist[nbr.node]}) ;
                }
            }
        }
        
        return ways[n-1] ;
    }
}

class Pair{
    int node, wt ;
    Pair(int node,  int wt){
        this.node =node;
        this.wt = wt ;
    }
}
