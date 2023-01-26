class Solution {
    public int minMutation(String start, String end, String[] bank) {
        HashSet<String> hs = new HashSet<>();
        for(String s : bank) hs.add(s);
        
        if(!hs.contains(end)) return -1;
        
        Queue<String> q = new ArrayDeque<>();
        q.add(start);
        
        int ans = 0;
        while(!q.isEmpty()) {
            
            int size = q.size();
            while(size-- > 0) {
                
                String dna = q.poll();
                
                if(dna.compareTo(end) == 0) return ans;
                
                if(hs.contains(dna)) hs.remove(dna);
                
                StringBuilder sb;
                
                for(int i = 0; i < 8; i++) {
                    
                    sb = new StringBuilder(dna);
                    
                    sb.setCharAt(i, 'A');
                    if(hs.contains(sb.toString())) q.add(sb.toString());
                    
                    sb.setCharAt(i, 'C');
                    if(hs.contains(sb.toString())) q.add(sb.toString());
                    
                    sb.setCharAt(i, 'G');
                    if(hs.contains(sb.toString())) q.add(sb.toString());
                    
                    sb.setCharAt(i, 'T');
                    if(hs.contains(sb.toString())) q.add(sb.toString());
                }
            }
            
            System.out.println(ans);
            
            ans += 1;
        }
        
        return -1;
    }
}
