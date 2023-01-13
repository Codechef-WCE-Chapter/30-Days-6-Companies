* Problem : https://leetcode.com/problems/airplane-seat-assignment-probability/description/

* Solution : 

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n == 1 ? (double)1 : (double)(1/2.0);
    }
};