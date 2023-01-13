class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double ans = 0;
        if(n==1){
            ans = 1;
            return ans;
        }
        ans = 0.5;
        return ans;
    }
};