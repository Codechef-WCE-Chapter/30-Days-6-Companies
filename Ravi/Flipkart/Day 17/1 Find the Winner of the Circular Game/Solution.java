class Solution {
    public int findTheWinner(int n, int k) {
        
        HashSet<Integer> hs = new HashSet<>();
        
        for(int i = 1; i <= n; i++) hs.add(i);
        
        int kk = k;
        while(hs.size() > 1) {
            
            ArrayList<Integer> hs2 = new ArrayList<>();
            // HashSet<Integer> hs2 = new HashSet<>();
            for(int i : hs) {
                
                kk--;
                if(kk == 0) {
                    hs2.add(i);
                    kk = k;
                }
                
            }
            
            
            for(int i : hs2) {
                if(hs.size() > 1) hs.remove(i);
            }
            
        }
        
        int ans = -1;
        for(int i : hs) ans = i;
        
        return ans;
        
    }
}
