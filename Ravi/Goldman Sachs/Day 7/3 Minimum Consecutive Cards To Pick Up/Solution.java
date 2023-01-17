class Solution {
    public int minimumCardPickup(int[] cards) {
        int low = 0;
        int high = 0;
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        int ans = Integer.MAX_VALUE;
        while(high < cards.length) {
            hm.put(cards[high], hm.getOrDefault(cards[high], 0) + 1);
            
            while(hm.get(cards[high]) >= 2) {
                hm.put(cards[low], hm.get(cards[low]) - 1);
                low++;
                ans = Math.min(ans, high - low + 2);
            }
            high++;
        }
        
        return ans != Integer.MAX_VALUE ? ans : -1;
        
    }
}
