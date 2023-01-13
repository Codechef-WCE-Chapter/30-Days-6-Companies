class Solution {
    
    /*
        - For each index, find the index of first a, b, c in the right of index
        - String starting from index, should end on maxNextIndex of a, b, c
          so all a, b, c will be contained in the string
        - from that maxNextIndex to n-1, string can end at any index
        - so increament ans by n - maxNextIndex
    */
    
    
    public int numberOfSubstrings(String s) {
        int n = s.length() ;
        int[] abcNextIndexMax = new int[n] ;
        
        int aIndex = n, bIndex = n, cIndex = n ;
        
        for(int i = n-1; i >= 0; i--) {
            if(s.charAt(i) == 'a'){
                aIndex = i ;
            } else if(s.charAt(i) == 'b'){
                bIndex = i ;
            } else if(s.charAt(i) == 'c'){
                cIndex = i ;
            }
            
            int ind = Math.max(aIndex, bIndex) ;
            ind = Math.max(ind, cIndex) ;
            
            abcNextIndexMax[i] = ind ;
        }
        
        int ans = 0 ;
        
        for(int i = 0; i < n; i++) {
            int endIndexOptions = n - abcNextIndexMax[i] ;
            ans += endIndexOptions ;
        }
        
        return ans ;
    }
}
