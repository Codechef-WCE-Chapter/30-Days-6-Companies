class Solution {
    
    public int mostProfitablePath(int[][] edges,
            int bob, int[] amount
            ) {

        // creating the graph/tree
        int n = edges.length + 1 ;
        ArrayList<Integer>[] adj = new ArrayList[n] ;
        
        for(int i = 0; i < n; i++){
            adj[i] = new ArrayList<>() ;
        }
        
        for(int[] edge: edges) {
            adj[edge[0]].add(edge[1]) ;
            adj[edge[1]].add(edge[0]) ;
        }
        
        // finding parent of each node
        HashMap<Integer, Integer> parents = new 
                                    HashMap<>() ;
        getParents(adj, parents, 0) ;
        
        // getting all nodes in bob's Path
        HashSet<Integer> bobsPath = new HashSet<>() ;
        int curr = bob ;
        while(parents.containsKey(curr)) {
            bobsPath.add(curr) ;
            curr = parents.get(curr) ;
        }
        bobsPath.add(0) ;
        
        // find the answer using DFS
        return dfs(adj, 0, bobsPath, 
                    parents, 0, amount
                ) ;
    }
    
    int dfs(ArrayList<Integer>[] adj, int node, 
             HashSet<Integer> bobsPath,
             HashMap<Integer, Integer> parents, 
             int level, int[] amount
            ) {
        
        int ans = 0 ;
        int max = Integer.MIN_VALUE ;
        
        // if there are several children of a node
        // Alice has choices for which node to go next
        // go to the node which gives maximum 
        // score, score for child is found using
        // recursive call for that child node
        for(int nbr: adj[node]) {
            if(parents.containsKey(node) 
                && parents.get(node) == nbr
            )
                continue ;

            int x = dfs(adj, nbr, 
                        bobsPath, parents,
                        level+1, amount
                    ) ;

            max  = Math.max(max, x) ;
        }
        
        if(max != Integer.MIN_VALUE) {
            ans = max ;
        }
        
        // if curNode is not present in bob's path,
        // it is sure that alice gets the amount
        // at that node
        if(!bobsPath.contains(node)) {
            ans += amount[node] ;
        } 
        // bob's path contains that node but alice reaches there first
        else
        if(level < bobsPath.size() / 2) {
            ans += amount[node] ;
        } 
        // alice and bob reach at that node simultaneously
        else if(bobsPath.size()%2 != 0 
            && level == bobsPath.size() / 2
            ) {
            ans += amount[node] / 2 ;
        }
        
        return ans ;
    }
    
    
    void getParents(ArrayList<Integer>[] adj,
        HashMap<Integer, Integer> parents,
        int node) {
        for(int nbr: adj[node]) {
            if(parents.containsKey(node) 
                && parents.get(node) == nbr
            )
                continue ;
            
            parents.put(nbr, node) ;
            getParents(adj, parents, nbr) ;
        }
    }
    
    
    
}
