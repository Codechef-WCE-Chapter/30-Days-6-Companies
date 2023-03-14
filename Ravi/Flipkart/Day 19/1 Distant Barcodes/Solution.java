class Pair {
    
    int f;
    int s;
    
    Pair(int a, int b) {
        f = a;
        s = b;
    }
    
}
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int b : barcodes) hm.put(b, hm.getOrDefault(b, 0) + 1);
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.f - a.f);
        for(Integer i : hm.keySet()) pq.add(new Pair(hm.get(i), i));
    
        
        int i = 0;
        while(!pq.isEmpty()) {
            
            Pair p = pq.poll();
            
            barcodes[i++] = p.s;
    
            
            
            if(pq.size() > 0) {
                Pair pp = pq.poll();
                barcodes[i++] = pp.s;
                
                if(p.f != 1) pq.add(new Pair(p.f - 1, p.s));
                if(pp.f != 1) pq.add(new Pair(pp.f - 1, pp.s));
                
            } else if(p.f != 1) pq.add(new Pair(p.f - 1, p.s));
        }
        
        
        return barcodes;
        
    }
}
