class Solution {
    public boolean isRectangleCover(int[][] rectangles) {

        // We increament by 1 for bottom-left and top-
        // right points, decreament for bottom-right
        // and top-left points.

        // If two rectangles have to be merged,
        // only 4 points should be present and rest all 
        // should be cancelled.
        
        // - For merging from right side, bottom right of one
        // rectangle should be bottom left of other rectangle
        // and top-right of one rectangle should be top-left of other.
        
        // - similarly for merging from the upper side,
        // top left of one rectangle should be bottom left of other
        // and top-right of one should be bottom-right of other.


        HashMap<Pair, Integer> map = new HashMap<>() ;

        for(int[] point: rectangles) {
            Pair p1 = new Pair(point[0], point[1]) ;
            Pair p2 = new Pair(point[2], point[1]) ;
            Pair p3 = new Pair(point[0], point[3]) ;
            Pair p4 = new Pair(point[2], point[3]) ;
            map.put(p1, map.getOrDefault(p1, 0)+1) ;
            map.put(p2, map.getOrDefault(p2, 0)-1) ;
            map.put(p3, map.getOrDefault(p3, 0)-1) ;
            map.put(p4, map.getOrDefault(p4, 0)+1) ;
        }

        int tot = 0 ;
        for(Pair p: map.keySet()) {
            if(map.get(p) != 0){
                tot++ ;
            }
        }

        int cnt = 0 ;
        for(int val: map.values()) {
            if(Math.abs(val) == 1){
                cnt++ ;
            }
        }
        return cnt == 4 && tot == 4;
    }
}

class Pair{
    int x, y ;
    Pair(int x, int y) {
        this.x = x;
        this.y = y ;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        Pair pair = (Pair) o;
        return x == pair.x && y == pair.y;
    }
}
