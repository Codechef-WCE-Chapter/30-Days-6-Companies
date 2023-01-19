class Solution {
    
    int maxm = -1;
    int[] ans;
    
    void maximum(int i, int numArrows, int[] aliceArrows, int[] curr) {
        
        if(i == 12) {
            
            curr[0] += numArrows;
            
            int sum = 0;
            for(int j = 0; j < 12; j++) {
                if(curr[j] > 0) sum += j;
            }
            
            if(sum > maxm) {
                maxm = sum;
                for(int j = 0; j < 12; j++) ans[j] = curr[j];
            }
            
            curr[0] -= numArrows;
            
            return;
        }
        
        if(numArrows > aliceArrows[i]) {
            
            curr[i] = (aliceArrows[i] + 1);
            
            maximum(i + 1, numArrows - curr[i], aliceArrows, curr);
            
            curr[i] = 0;
        }
        
        maximum(i + 1, numArrows, aliceArrows, curr);
        
    }
    
    public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
        
        ans = new int[12];
        
        int[] curr = new int[12];
        
        maximum(0, numArrows, aliceArrows, curr);
        
        return ans;
        
    }
    
}
