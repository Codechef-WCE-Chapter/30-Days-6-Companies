/*

Approach: Mathematical Induction:

CAse 1: 1 seat-

Prob = 1;

Case 2: 2 seats 
P2 = 1/2;

Case 3 : 3 seats-
P3 = (1/3)*1 + (1/3)*0 + (1/3)*p2;
P3 = 1/2;

Similarly for ....

Pn = 1/2;

Output- IF n =1 then prob is 1 and for all the other cases prob is 1/2;

*/



class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans =0;
        if(n == 1){
            return 1;

        }

        else {
            return 0.5;
        }

       
        
    }
};
