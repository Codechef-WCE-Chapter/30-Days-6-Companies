class Solution {
    public int magicalString(int n) {
        
        StringBuilder sb = new StringBuilder("");
        sb.append("122");
        
        int low = 2;
        char prev = '2';
        
        while(sb.length() < n) {
            int tim = (int)(sb.charAt(low) - '0');
            for(int i = 0; i < tim; i++) {
                if(prev == '2') sb.append('1');
                else sb.append('2');
            }
            low++;
            if(prev == '2') prev = '1';
            else prev = '2';
        }
        
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(sb.charAt(i) == '1') ans++;
        }
        
        return ans;
        
    }
}
