class Pair {
    int f;
    int s;
    
    Pair(int a, int b) {
        f = a;
        s = b;
    }
}

class Solution {
    
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        
        ArrayList<Pair> arr = new ArrayList<>();
        
        for(int i = 0; i < profits.length; i++) {
            arr.add(new Pair(capital[i], profits[i]));
        }
        
        Collections.sort(arr, (a, b) -> a.f - b.f);
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        
        // for(Pair p : arr) System.out.println(p.f + " " + p.s);
        
        int i = 0;
        int ans = w;
        while(i < profits.length) {
            
            if(k == 0) break;
            
            while(i < profits.length && arr.get(i).f <= ans) {
                pq.add(arr.get(i).s);
                i++;
            }
            
            if(pq.isEmpty()) break;
            
            ans += pq.poll();
            k--;
            
        }
        
        while(k > 0 && !pq.isEmpty()) {
            ans += pq.poll();
            k--;
        }
        
        return ans;
        
    }
}
