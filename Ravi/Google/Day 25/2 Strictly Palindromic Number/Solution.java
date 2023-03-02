class Solution {
    
    boolean isPalindrome(String s) {
        int l = 0, h = s.length() - 1;
        while(l <= h) {
            if(s.charAt(l) != s.charAt(h)) return false;
            l++;
            h--;
        }
        return true;
    }
    
    public boolean isStrictlyPalindromic(int n) {
        
        for(int i = 2; i <= n - 2; i++) {
            int r = n;
            String s = "";
            while(r > 0) {
                int l = r % i;
                r /= i;
                s += (char)(l + '0');
            }
            if(!isPalindrome(s)) return false;
        }
        return true;
    }
}
