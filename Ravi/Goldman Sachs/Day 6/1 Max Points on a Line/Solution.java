class Solution {
    public int maxPoints(int[][] points) {
        int ans = 0;
        int n = points.length;
        if(n <= 2) return n;
        
        for(int i = 0; i < n; i++) {
            HashMap<Double, Integer> hm = new HashMap<>();
            int curr = 0;
            for(int j = 0; j < n; j++) {
                double s = ((points[j][1] - points[i][1]) * (1.0)) / ((points[j][0] - points[i][0]) * (1.0));
                hm.put(s, hm.getOrDefault(s, 1) + 1);
                curr = Math.max(curr, hm.get(s));
            }
            
            ans = Math.max(ans, curr);
            
        }
        return ans;
    }
}
