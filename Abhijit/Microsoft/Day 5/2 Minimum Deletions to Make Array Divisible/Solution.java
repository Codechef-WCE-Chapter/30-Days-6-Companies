class Solution 
{
    /*
        - Find the GCD of numsDivide. 
        - The number which divides GCD can divide all numbers in numsDivide
        - Sort the nums and remove numbers while smallest num doesn't divide GCD
    */
    
    public int minOperations(int[] nums, int[] numsDivide) 
    {
        int n = nums.length ;
        Arrays.sort(nums) ;
     
        int g = numsDivide[0] ;
        
        for (int x :  numsDivide){
            g = gcd(x, g) ;
        }
        
        int ans = 0 ;
        
        int i = 0 ;
        
        while (i < n && g%nums[i] != 0){
            ans++ ;
            i++ ;
        }
        
        return ans == n ? -1 : ans ;
    }
    
    private static int gcd(int a, int b) {
        if (b == 0) return a ;
        return gcd(b,  a%b) ;
    }

    
    
    
}
