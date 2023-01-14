class Solution {
    
    /*
        1) Fix one point
        2) Calculate slope with every other point and store in map
           The Points which have same slope with fixed point will 
           all lie on a same line
        3) Out of all the values, update the answer with slope having
           maximum frequency
        
        Do these steps by fixing every point one by one by and return the maximum 
        answer
    */
    
    
    public int maxPoints(int[][] points)  {
        int ans = 0 ;
        int n = points.length ;
        
        for(int i = 0 ; i < n; i++) {
            // x1, y1 is fixed point
            int x1 = points[i][0] ;
            int y1 = points[i][1] ;
            
            HashMap<Double, Integer> map = new HashMap<>() ;
            
            // storing slopes with fixed point in map
            for(int j = i+1; j < n; j++) {
                int x2 = points[j][0] ;
                int y2 = points[j][1] ;
                
                double slope = (y2-y1)*1.0 / (x2 - x1) ;
                
                if(slope == -0.0) {
                    slope = 0.0 ;
                }
                
                if(slope == Double.NEGATIVE_INFINITY) {
                    slope = Double.POSITIVE_INFINITY ;
                }
                
                // updating answer
                map.put(slope, map.getOrDefault(slope, 0)+1) ;
                ans = Math.max(ans,map.get(slope)) ;
            }  
        }
        
        // +1 because we have not consider the fixed point while 
        // updating the answer
        return ans + 1 ;
    }
}
