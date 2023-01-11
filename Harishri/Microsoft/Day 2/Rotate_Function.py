class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        v, s = 0, sum(nums)
        for i in range(len(nums)):
            v += i * nums[i]
        maxi = v
        for x in reversed(nums):
            # print(x,"x")
            v -= x * len(nums) - s
            # print(v,'v')
            if v > maxi:
                maxi = v        

        return maxi
                
