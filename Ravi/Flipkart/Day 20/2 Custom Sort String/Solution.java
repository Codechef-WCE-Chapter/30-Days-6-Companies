class Solution {
    public String customSortString(String order, String s) {
        
        HashMap<Character, Integer> hm = new HashMap<>();
        for(int i = 0; i < order.length(); i++) hm.put(order.charAt(i), i);
        
        PriorityQueue<Character> pq  = new PriorityQueue<>((a, b) -> hm.getOrDefault(a, 0) - hm.getOrDefault(b, 0));
        
        for(int i = 0; i < s.length(); i++) pq.add(s.charAt(i));
        
        StringBuilder ans = new StringBuilder("");
        
        while(!pq.isEmpty()) ans.append(pq.poll());
        
        return ans.toString();
        
    }
}
