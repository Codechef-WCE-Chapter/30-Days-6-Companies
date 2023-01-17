class Solution {
  
   // We will try to find the number of 5 as the divisors in all the numbers upto N
  
  // Feel it, to make a trailing zero we need to obtain 10
  // 10 can be obtained as 5 x 2
  
  // So, if we need to count minimum of 5 and 2 in all the divisors upto N
  
  // Let's do it
  
  // 2 - 2
  // 3 - 3
  // 4 - 2 x 2
  // 5 - 5
  // 6 0 2 x 3
  // 7 - 7
  // 8 - 2 x 2 x 2
  // 9 - 3 x 3
  // 10 - 2 x 5
  
  // So, we can clearly see that we need to calculate no of 5 only, because number of 2 will always be greater than number of 5s
  
  // To get more clarification, try writing it upto 25 !! You will be amazed !!!
  
  
  // Now, to find number of 5s simply we can see how many divisors of 5 are there
  // i.e keep dividing n by 5 and keep adding the rmainder to the answer !!!
  
    public int trailingZeroes(int n) {
        
        int ans = 0;
        
        while(n > 0) {
            n /= 5;
            ans += n;
        }
        
        return ans;
        
    }
}
