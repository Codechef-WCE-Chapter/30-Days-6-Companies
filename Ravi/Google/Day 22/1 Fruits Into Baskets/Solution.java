class Solution {
    public int totalFruit(int[] fruits) {
        
        int prev = -1;
        int n = fruits.length;
        
        int st = 0;
        int ans = 0;
        
        HashSet<Integer> hs = new HashSet<>();
        for(int i = 0; i < n; i++) {
            hs.add(fruits[i]);
            if(hs.size() > 2) {
                
                hs = new HashSet<>();
                hs.add(fruits[prev]);
                hs.add(fruits[i]);
                
                ans = Math.max(ans, i - st);
                st = prev;
                
            }
            
            if(prev == -1 || fruits[prev] != fruits[i]) prev = i;
            
        }
        
        ans = Math.max(ans, n - st);
        
        return ans;
        
    }
}
