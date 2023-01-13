import math
class Solution:
    def minOperations(self, nums: list[int], numsDivide: list[int]) -> int:
        gcd=0
        for i in numsDivide:
            gcd=int(math.gcd(gcd,i))
        nums.sort()
        for i in range(len(nums)):
            if gcd%nums[i]==0:
                return i
        return -1