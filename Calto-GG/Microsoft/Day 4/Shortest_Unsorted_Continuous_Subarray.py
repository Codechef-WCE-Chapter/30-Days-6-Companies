# Approach 1 - Intuative O(nLogn) solution just sorted it and compared the differences.

class Solution:
    def findUnsortedSubarray(self, nums: list[int]) -> int:
        new = sorted(nums)
        poppy = []
        if new == nums: return 0
        for i in range(len(nums)):
            if nums[i] != new[i]: poppy.append(i)
        return poppy[-1] - poppy[0] + 1

# Approach 2 - Using Two Pointers .....

class Solution:
    def findUnsortedSubarray(self, nums: list[int]) -> int:
        n = len(nums)
        start, end = -1, -2
        min_val, max_val = nums[n-1], nums[0]
        
        # find the first element (from left) that breaks the increasing order
        for i in range(1, n):
            max_val = max(max_val, nums[i])
            if nums[i] < max_val:
                end = i
        
        # find the first element (from right) that breaks the decreasing order
        for i in range(n-2, -1, -1):
            min_val = min(min_val, nums[i])
            if nums[i] > min_val:
                start = i
        if end - start <= 0:
            return 0
        else:
            return end - start + 1

    # here max_val and min_val are used to keep track of the largest element while traversing.