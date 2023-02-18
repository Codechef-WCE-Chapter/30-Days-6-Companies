class Solution {
    
    List<String> ans;
    
    void helper(String s, String curr, int k) {
        
        if(k == 4) {
            if(s.length() == 0) ans.add(curr.substring(0, curr.length() - 1));
            return;
        }
        
        for(int i = 0; i < 3; i++) {
            if(i == s.length()) break;
            String str = s.substring(0, i + 1);
            if(Integer.parseInt(str) > 255 || (str.length() > 1 && str.charAt(0) == '0')) break;
            helper(s.substring(i + 1, s.length()), curr + str + ".", k + 1);
        }
    }
    
    public List<String> restoreIpAddresses(String s) {
        ans = new ArrayList<>();
        helper(s, "", 0);
        return ans;
    }
}
