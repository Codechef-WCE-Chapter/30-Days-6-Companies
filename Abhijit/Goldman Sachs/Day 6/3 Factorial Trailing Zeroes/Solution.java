class Solution {
    
    /*
        * The zero will be contributed by every 10 in the factors
        * 10 = 5*2
        * The count of 2 will always be greater than 2
        * So count the frequency of factor 5 in given factorial
        * ans = n / 5 + n / 25 + n / 125 + .... 
    */
    
    public int trailingZeroes(int n) {
        int ans = 0 ;
        int pow = 5 ;
        
        while(pow <= n){
            ans += n / pow ;
            pow *= 5 ;
        }
        
        return ans ;
    }
}
