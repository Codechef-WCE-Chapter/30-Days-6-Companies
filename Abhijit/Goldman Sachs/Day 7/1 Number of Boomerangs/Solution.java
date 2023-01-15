class Solution {
    
    /*
        - For every point, calculate distance with every other point and store in map
        - we have to select two points from a same unique value of distance
        - for that point, ans += SUM(nC2) where n is frequence of each distance d
    */
    
    public int numberOfBoomerangs(int[][] points) {
        int ans = 0 ;
        int n = points.length ;
        
        for(int i = 0; i < n; i++){
            HashMap<Integer, Integer> map = new HashMap<>()  ;
            for(int j = 0; j < n; j++){
                int d = (points[i][0] - points[j][0])*(points[i][0] - points[j][0])
                        +  (points[i][1] - points[j][1])*(points[i][1] - points[j][1]) ;
                ans += map.getOrDefault(d, 0) ;
                map.put(d, map.getOrDefault(d, 0)+1) ;
            }
        }
        
        return 2*ans ;
    }
}
