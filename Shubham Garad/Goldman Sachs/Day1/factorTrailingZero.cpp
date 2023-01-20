class Solution {
public:
    int trailingZeroes(int n) {

     int count =0 ;
     while(n>0)
     {
         n = n/5;
         count += n;
     }   

     return count;
    }
};