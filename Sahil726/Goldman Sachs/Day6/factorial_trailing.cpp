class Solution {
public:
    int trailingZeroes(int n,int x=5) {
        if(x>n) return 0;
        return n/5 + trailingZeroes(n/5,x);
    }
};
