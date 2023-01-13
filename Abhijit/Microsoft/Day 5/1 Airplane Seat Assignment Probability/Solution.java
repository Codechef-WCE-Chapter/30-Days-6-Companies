class Solution {
    /*
        F(1) = 1
        F(2) = F(1) / 2

        F(3) = (F(1) + F(2)) / 3
             = (F(1) + F(1) / 2) / 3
             = F(1) / 2 

        F(4) = (F(1) + F(2) + F(3)) / 4
             = (F(1) + F(1) / 2 + F(1) / 2) / 4
        .
        .
        .

        F(n) = (F(1) + F(1) / 2 * (n-2)) / n
             = (1 + (n-2)/2)n 
             = 1 / n + (n-2)/2n 
             = n/ 2 n = 1/2
    */
    
    public double nthPersonGetsNthSeat(int n) {
        if(n == 1){
            return 1 ;
        } 
        return 0.5 ;
    }
}
