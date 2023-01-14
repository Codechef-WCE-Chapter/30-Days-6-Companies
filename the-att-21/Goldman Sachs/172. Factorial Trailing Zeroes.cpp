* Problem : https://leetcode.com/problems/factorial-trailing-zeroes/description/

* Solution : 

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;

        for(int i = 5; n / i >= 1; i *= 5){
            ans += floor(n / i);
        }

        return ans;
    }
};