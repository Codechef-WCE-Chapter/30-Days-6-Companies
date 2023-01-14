// We will simply calculate the distance between all pairs of points and push them into distance array
// Then we will sort the distance array
// Then first 4 points should represent 4 sides of square and next 2 points should represent 2 diagonals of square
// Just check whether 4 sides and 2 diagonals are equal or not !!!

class Solution {
    
    int getDis(int[] p1, int[] p2) {
        int x1 = p1[0];
        int x2 = p2[0];
        int y1 = p1[1];
        int y2 = p2[1];
        
        x1 = (x1 - x2) * (x1 - x2);
        y1 = (y1 - y2) * (y1 - y2);
        
        x1 = x1 + y1;
        return x1;
        
    }
    
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        
        int[] dis = new int[6];
        
        dis[0] = (getDis(p1, p2));
        dis[1] = (getDis(p1, p3));
        dis[2] = (getDis(p1, p4));
        dis[3] = (getDis(p2, p3));
        dis[4] = (getDis(p2, p4));
        dis[5] = (getDis(p3, p4));
        
        Arrays.sort(dis);
        
        System.out.println(dis);
        
        boolean f1 = dis[(0)] == dis[(1)];
        boolean f2 = dis[(1)] == dis[(2)];
        boolean f3 = dis[(2)] == dis[(3)];
        boolean f4 = dis[(4)] == dis[(5)];
        boolean f5 = dis[(0)] != 0;
        
        System.out.println(f1 + " " + f2 + " " + f3 + " " + f4 + " " + f5);
        
        
        if(f1 && f2 && f3 && f4 && f5) return true;
        return false;
        
        
    }
}
