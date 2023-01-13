class Solution(object):
    def largestDivisibleSubset(self, nums):
        if not nums:
            return []
        nums.sort()
        # initialize the list dp with the same size as nums
        dp = [1] * len(nums)
        predecessor = [-1] * len(nums)
        max_size = 0
        max_index = -1
        for i, num in enumerate(nums):
            for j in range(i):
                if nums[i] % nums[j] == 0 and dp[i] < dp[j] + 1:
                    dp[i] = dp[j] + 1
                    predecessor[i] = j
            #update the maximum subset size and index if dp[i] is greater than the current maximum
            if dp[i] > max_size:
                max_size = dp[i]
                max_index = i
        # reconstruct the maximum divisible subset
        result = []
        while max_index >= 0:
            result.append(nums[max_index])
            max_index = predecessor[max_index]
        return result