class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;

        while(n){
            ans += n/5;
            n /= 5;
        }

        return ans;
    }
};
