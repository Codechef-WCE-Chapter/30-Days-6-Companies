class Solution {
    public int numberOfBoomerangs(int[][] points) {
        
        int ans = 0;
        
        for(int i = 0; i < points.length; i++) {
            
            HashMap<Integer, Integer> hm = new HashMap<>();
            
            for(int j = 0; j < points.length; j++) {
                
                if(i != j) {
                    
                    int dis = (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]) + (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
                    
                    hm.put(dis, hm.getOrDefault(dis, 0) + 1);
                    
                }
            }
            
            for(int it : hm.keySet()) {
                
                if(hm.get(it) >= 2) ans += ((hm.get(it)) * (hm.get(it) - 1));
            
            }
        }
        
        
        return ans;
        
    }
}
