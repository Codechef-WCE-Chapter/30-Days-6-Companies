class Solution {
    public int minimumCardPickup(int[] cards) {
        HashMap<Integer, Integer> prevIndex = new HashMap<>() ;
        int n = cards.length ;
        
        int ans = Integer.MAX_VALUE ;
        
        for(int i = 0; i < n; i++){
            if(prevIndex.containsKey(cards[i])) {
                int curAns = i - prevIndex.get(cards[i]) + 1;
                ans = Math.min(ans, curAns) ;
            }
            prevIndex.put(cards[i], i) ;
        }
        
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
