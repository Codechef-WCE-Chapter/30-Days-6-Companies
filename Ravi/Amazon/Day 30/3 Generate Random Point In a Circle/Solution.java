class Solution {

    double x;
    double y;
    double r;
    boolean f = true;
    public Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        r = radius;
    }
    
    public double[] randPoint() {
        double ang = Math.random() * 2 * Math.PI;
        double hyp = Math.sqrt(Math.random()) * r;
        double adj = Math.cos(ang) * hyp;
        double opp = Math.sin(ang) * hyp;
        return new double[]{x + adj, y + opp};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
