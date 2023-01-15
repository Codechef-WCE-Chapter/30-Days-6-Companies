class Solution {
    public boolean isPossible(int[] nums) {
        PriorityQueue<Interval> pq = new PriorityQueue<>((i1, i2) -> {
            if(i1.end == i2.end){
                return i1.length - i2.length ;
            }
            return i1.end - i2.end;
        }) ;
        
        for(int num: nums) {
            while(!pq.isEmpty() && pq.peek().end + 1 < num) {
                if(pq.peek().length < 3)
                    return false ;
                pq.poll() ;
            }
            
            if(pq.isEmpty() || pq.peek().end == num) {
                pq.add(new Interval(num, num)) ;
            }
            else {
                int start = pq.peek().start ;
                pq.poll() ;
                pq.add(new Interval(start, num)) ;
            }
        }
        
        while(!pq.isEmpty()) {
            if(pq.peek().length < 3)
                return false ;
            pq.poll() ;
        }
        
        return true ;
    }
}

class Interval{
    int start, end, length ;
    
    Interval(int start, int end) {
        this.start = start ;
        this.end = end ;
        this.length = end - start + 1 ;
    }
}
