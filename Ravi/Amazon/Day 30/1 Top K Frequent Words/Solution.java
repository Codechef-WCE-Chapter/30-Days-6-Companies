class Pair {
    
    int f;
    String s;
    
    Pair(int a, String b) {
        f = a;
        s = b;
    }
    
}
class Solution {
    
    public List<String> topKFrequent(String[] words, int k) {
        
        HashMap<String, Integer> hm = new HashMap<>();
        
        for(String w : words) hm.put(w, hm.getOrDefault(w, 0) + 1);
        
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.f == b.f ? a.s.compareTo(b.s) : b.f - a.f);
        
        for(String s : hm.keySet()) {
            pq.add(new Pair(hm.get(s), s));
        }
        
        List<String> ans = new ArrayList<>();
        while(k-- > 0) ans.add(pq.poll().s);
        
        return ans;
        
    }
}
