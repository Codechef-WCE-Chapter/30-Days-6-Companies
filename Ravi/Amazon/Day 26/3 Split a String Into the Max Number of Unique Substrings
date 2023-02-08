class Solution {
    
    HashSet<String> hs = new HashSet<>();
    int ans = 0;
    
    void maximumsplit(int i, int prev, String s) {
        
        if(i == s.length()) {
            ans = Math.max(ans, hs.size());
            return;
        }
        
        String ss = s.substring(prev, i + 1);
        if(!hs.contains(ss)) {
            hs.add(ss);
            maximumsplit(i + 1, i + 1, s);
            hs.remove(ss);
        }
        
        maximumsplit(i + 1, prev, s);
        
    }
    
    public int maxUniqueSplit(String s) {
        maximumsplit(0, 0, s);
        return ans;
    }
}
