class Solution {
    public boolean hasAllCodes(String s, int k) {
        
        HashSet<String> hs = new HashSet<>();
        
        for(int i = 0; i < s.length() - k + 1; i++) hs.add(s.substring(i, i + k));
        
        if(hs.size() == (1 << k)) return true;
        
        return false;
        
    }
}
