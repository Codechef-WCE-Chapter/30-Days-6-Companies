class Solution {
    
    TreeMap<Integer, Integer> tm = new TreeMap<>();
    
    int curr = 0;

    public Solution(int[] w) {
        
        for(int i = 0; i < w.length; i++) {
            curr += w[i];
            tm.put(curr, i);
        }
        
    }
    
    public int pickIndex() {
        
        int ind = tm.higherKey(new Random().nextInt(curr));
        
        return tm.get(ind);
        
        
        
    }
}
