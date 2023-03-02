class Solution {
public:
    
    bool isPalindrome(string s) {
        int l = 0, h = s.size() - 1;
        while(l <= h) {
            if(s[l] != s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        
        for(int i = 2; i <= n - 2; i++) {
            int r = n;
            string s = "";
            while(r > 0) {
                int l = r % i;
                r /= i;
                s += (l + '0');
            }
            if(!isPalindrome(s)) return false;
        }
        return true;
    }
};
