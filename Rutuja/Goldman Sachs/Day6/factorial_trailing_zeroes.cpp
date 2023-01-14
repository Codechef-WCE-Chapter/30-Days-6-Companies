/*
https://leetcode.com/problems/factorial-trailing-zeroes/description/
*/

#include<bits/stdc++.h>
using namespace std;

/* 
Approach:

- Step1: Count no. of pairs of 5's and 2's in the factorial of given no. ( 5 and 2 -> contribute to 0)
- Step2: No. of 2's > No. of 5's (always) -> Count just no. of 5's

*/
class Solution {
public:
    int trailingZeroes(int n) {
        int trailingZeroes=0, c5=0, c2=0, c25=0;
        int div= INT_MAX, pow=5;
        while(div > 0)
        {
            div = n/pow;
            pow *=5;
            trailingZeroes += div;
        }

        // if(n==0)
        // trailingZeroes=0;
        // else{
        //     for(int i=1; i<=n; i++)
        //     {
        //         if(i%5==0 && i%2!=0)
        //         {
        //             if(i % 25 !=0)
        //             {
        //                 if(ceil(log10(i)/log10(5))==floor(log10(i)/log10(5)))
        //                 c5+= log10(i)/log10(5);
        //                 else if( ceil(log10(i)/log10(5))!=floor(log10(i)/log10(5))  )
        //                 c5+= 1;
        //             }
        //             else if( i % 25==0)
        //             {
        //                 c5+= log10(i)/log10(5);
        //             }  

        //         }
        //         else if(i%2==0 && i%5==0)
        //         {
        //             if(i % 25==0)
        //             {
        //                 if(ceil(log10(i))==floor(log10(i))   )
        //                 {
        //                 c25+=log10(i);
        //                 }
        //                 else  
        //                 c25+=ceil(log10(i)) ;
        //             }
        //             else 
        //             {

        //                 c25+=log10(i);
        //             }

                  
        //         }
        //         // else if(i%2==0 && i%5!=0)
        //         // {
        //         //     if(ceil(log2(i))==floor(log2(i))  )
        //         //     c2+= log2(i);
        //         //     else if(ceil(log2(i))!=floor(log2(i))  )
        //         //     c2+= (log2(i) - 1);
        //         // }
            
        //     }
     


        //     trailingZeroes =  c5 + c25;
        // }


    
        return trailingZeroes;
    }
};