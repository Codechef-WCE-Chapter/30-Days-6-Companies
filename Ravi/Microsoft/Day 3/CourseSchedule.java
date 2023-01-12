class Solution {
    
    boolean dfs(int node, int[] vis, int[] dfsvis, ArrayList<Integer> adj[]) {
        vis[node] = 1;
        dfsvis[node] = 1;
        for(int i : adj[node]) {
            if(vis[i] == 0) 
            {
                if(dfs(i, vis, dfsvis, adj)) return true;
            } else if(dfsvis[i] == 1) return true;
        }
        dfsvis[node] = 0;
        return false;
    }
    
    public boolean canFinish(int n, int[][] p) {
        
        ArrayList<Integer> adj[] = new ArrayList[n];
        
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        
        int []vis = new int[n];
        int []dfsvis = new int[n];
        
        for(int i = 0; i < p.length; i++) {
            adj[p[i][0]].add(p[i][1]);
        }
        
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                if(dfs(i, vis, dfsvis, adj)) return false;
            }
        }
        
        return true;
        
    }
}
