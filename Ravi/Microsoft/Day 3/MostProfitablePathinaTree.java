class Solution {
    
    int ans = Integer.MIN_VALUE;
    
    boolean dfs(int node, ArrayList<Integer> adj[], int[] vis, int[] dis, int curr) {
        
        vis[node] = 1;
        
        if(node == 0) {
            dis[node] = curr;    
            return true;
        }
        
        boolean flag = false;
        
        for(int i : adj[node]) {
            if(vis[i] == 0) {
                if(dfs(i, adj, vis, dis, curr + 1)) {
                    flag = true;
                    break;
                }
            }
        }
        
        if(flag) {
            dis[node] = curr;
            return true;
        }
        
        return false;
        
    }
    
    void dfs2(int node, ArrayList<Integer> adj[], int[] vis, int[] dis, int curr, int cost, int[] amount) {
        
        vis[node] = 1;
        
        if(dis[node] > curr) cost += amount[node];
        else if(dis[node] == curr) cost += (amount[node] / 2);
        
        for(int i : adj[node]) {
            if(vis[i] == 0) dfs2(i, adj, vis, dis, curr + 1, cost, amount);
        }
        
        if(node != 0 && adj[node].size() == 1) ans = Math.max(ans, cost);
        
    }
    
    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        
        int n = amount.length;
        ArrayList<Integer> adj[] = new ArrayList[n];
        for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();  
        
        for(int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        
        int[] dis = new int[n];
        for(int i = 0; i < n; i++) dis[i] = (int)(1e8);
        
        int[] vis = new int[n];
        
        dfs(bob, adj, vis, dis, 0);

        vis = new int[n];
        dfs2(0, adj, vis, dis, 0, 0, amount);
        
        return ans;
        
    }
}
