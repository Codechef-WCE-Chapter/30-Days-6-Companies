import java.util.Vector;
import static java.lang.Math.sqrt;
import static java.lang.Math.floor;

class Solution {
    
    HashSet<Integer> hs = new HashSet<>();
    void simpleSieve(int limit, Vector<Integer> prime) {
        boolean mark[] = new boolean[limit + 1];
         
        for(int i = 0; i < mark.length; i++) mark[i] = true;
      
        for(int p = 2; p * p < limit; p++) {
            if(mark[p] == true) {
                for(int i = p * p; i < limit; i += p) mark[i] = false;
            }
        }
      
        for(int p = 2; p < limit; p++)
        {
            if (mark[p] == true) {
                prime.add(p);
                hs.add(p);
            }
        }
    }
      
    void segmentedSieve(int n) {
        int limit = (int) (floor(sqrt(n)) + 1);
        Vector<Integer> prime = new Vector<>(); 
        simpleSieve(limit, prime);

        int low  = limit;
        int high = 2 * limit;

        while (low < n) {
            if(high >= n) high = n;

            boolean mark[] = new boolean[limit + 1];
             
            for(int i = 0; i < mark.length; i++) mark[i] = true;
      
            for(int i = 0; i < prime.size(); i++) {
 
                int loLim = (int) (floor(low / prime.get(i)) * prime.get(i));
                if(loLim < low) loLim += prime.get(i);
 
                for(int j = loLim; j < high; j += prime.get(i)) mark[j - low] = false;
            }
      
            for(int i = low; i < high; i++) if(mark[i - low] == true) hs.add(i);

            low  = low + limit;
            high = high + limit;
        }
    }
    
    public int[] closestPrimes(int left, int right) {
        segmentedSieve(right + 1);
        
        int prev = -1;
        
        int ans = Integer.MAX_VALUE;
        int f = -1;
        int s = -1;
        for(int i = left; i <= right; i++) {
            if(hs.contains(i)) {
                if(prev == -1) prev = i;
                else {
                    if(i - prev < ans) {
                        ans = i - prev;
                        f = prev;
                        s = i;
                    }
                    prev = i;
                }
            }
        }
        
        int[] fans = new int[2];
        fans[0] = f;
        fans[1] = s;
        return fans;
        
    }
}
