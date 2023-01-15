# Simple Intuition -> divide n by 5 until it gets null
class Solution:
    def trailingZeroes(self, n: int) -> int:
        ans = 0
        while n!=0:
            n = n//5
            ans += n
        return ans