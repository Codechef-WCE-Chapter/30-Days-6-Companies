class Solution {
    
    boolean isSub(String ss, String s) {
        
        int i = 0;
        int j = -1;
        
        while(i < ss.length()) {
            j = s.indexOf(ss.charAt(i), j + 1);
            if(j == -1) return false;
            i++;
        }
        
        return true;
        
    }
    
    public int numMatchingSubseq(String s, String[] words) {
        
        int ans = 0;
        for(String ss : words) {
            if(isSub(ss, s)) ans++;
        }
        
        return ans;
        
    }
}
