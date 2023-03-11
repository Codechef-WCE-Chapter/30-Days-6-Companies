class Solution {
    
    // int ans = (int)(1e9);
    
    int shoppingoffers(int i, int curr, int[] prices, int[][] specials, int[] needs) {
        
        if(i == specials.length) {
            
            int ans = 0;
            for(int j = 0; j < needs.length; j++) ans += (prices[j] * needs[j]);
            
            return curr + ans;
            
        }
        
        int take = (int)(1e9);
        
        boolean is = true;
        for(int j = 0; j < needs.length; j++) {
            if(specials[i][j] > needs[j]) {
                is = false;
                break;
            }
        }
        
        if(is) {
            
            for(int j = 0; j < needs.length; j++) needs[j] -= specials[i][j];
            take = shoppingoffers(i, curr + specials[i][needs.length], prices, specials, needs);
            for(int j = 0; j < needs.length; j++) needs[j] += specials[i][j];
            
        }
        
        int nottake = shoppingoffers(i + 1, curr, prices, specials, needs);
        
        return Math.min(take, nottake);
        
    }
    
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        
        int curr = 0;
        int n = price.size();
        for(int i = 0; i < n; i++) curr += needs.get(i) * price.get(i);
        
        int[] need = new int[n];
        int[][] specials = new int[special.size()][n + 1];
        int[] prices = new int[n];
        for(int i = 0; i < n; i++) {
            need[i] = needs.get(i);
            prices[i] = price.get(i);
        }
        
        for(int i = 0; i < special.size(); i++) {
            
            for(int j = 0; j < special.get(i).size(); j++) specials[i][j] = special.get(i).get(j);
            
        }
        
        // ans = Math.min(ans, curr);
        
        return shoppingoffers(0, 0, prices, specials, need);
        
        // return ans;
    }
}
