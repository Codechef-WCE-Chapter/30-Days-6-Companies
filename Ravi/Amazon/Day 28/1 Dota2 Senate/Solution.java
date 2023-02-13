class Solution {
    public String predictPartyVictory(String s) {
        
        Queue<Character> q = new ArrayDeque<>();
        
        for(int i = 0; i < s.length(); i++) q.add(s.charAt(i));
        
        int r = 0;
        int d = 0;
        while(q.size() > 1) {
            
            int size = q.size();
            
            int temp = size;
            
            while(size-- > 0) {
                
                char c = q.poll();
                if(c == 'R') {
                    if(r > 0) r--;
                    else {
                        q.add('R');
                        d++;
                    }
                } else {
                    if(d > 0) d--;
                    else {
                        q.add('D');
                        r++;
                    }
                }
                
            }
            
            if(q.size() == temp) break;
            
        }
        
        char cc = q.poll();
        
        if(cc == 'R') return "Radiant";
        return "Dire";
        
    }
}
