class Solution {
    
    int gcd(int a,int b) {
	    if(b == 0) return a;
	    return gcd(b, a % b);
    }
    
    public int minOperations(int[] nums, int[] numsDivide) {
        int n = numsDivide.length;
        int g = numsDivide[0];
        
        for(int i = 1; i < n; i++) g = gcd(g, numsDivide[i]);
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int ans = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i : nums) hm.put(i, hm.getOrDefault(i, 0) + 1);
        
        for(Integer i : hm.keySet()) {
            pq.add(i);
        }
        
        while(!pq.isEmpty()) {
            
            int gg = pq.poll();
            
            if(g % gg == 0) return ans;
            
            ans += hm.get(gg);
            
        }
        
        return -1;
        
    }
}
