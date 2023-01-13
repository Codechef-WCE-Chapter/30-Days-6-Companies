class Solution {
    public String longestPrefix(String s) {
        
        int n = s.length();
        
        int lhp[] = new int[n];
        
        int i = 1;
        int curr = 0;
        
        while(i < n) {
            
            if(s.charAt(i) == s.charAt(curr)) {
                curr++;
                lhp[i] = curr;
                i++;
            } else{
                if(curr > 0) curr = lhp[curr - 1];
                else {
                    lhp[i] = 0;
                    i++;
                }
            }
        }
        
        return s.substring(0, lhp[n - 1]);
    }
}
