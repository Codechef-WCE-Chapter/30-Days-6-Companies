class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 0)
        return -1;

    int count = 0;
 
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
 
    return count;
    }
};
