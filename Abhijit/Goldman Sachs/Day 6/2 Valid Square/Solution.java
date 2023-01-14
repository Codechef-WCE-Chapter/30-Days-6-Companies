class Solution {
    
    /*
        - Calculate distance between every two points
        - There will be 2 types of lines:
           Side of Square and Diagonal of Square
        - So there must be two values in Set of distance
           between two points
        - Also no distance should be zero
        
        - For simplicity, here I have stored square of distance
    
    */
    
    
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4){
        
        HashSet<Integer> set = new HashSet<>();
        set.add(dist(p1, p2));
        set.add(dist(p1, p3));
        set.add(dist(p1, p4));
        set.add(dist(p2, p3));
        set.add(dist(p2, p4));
        set.add(dist(p3, p4));
    
        return !set.contains(0) && set.size() == 2;
    }
    
    int dist(int[] p1, int[] p2) {
        int d = (p1[0] - p2[0])*(p1[0] - p2[0]) +
                (p1[1] - p2[1])*(p1[1] - p2[1]);
        
        return d;
    }
    
    
}
