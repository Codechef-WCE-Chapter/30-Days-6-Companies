class Solution(object):
    def maxRotateFunction(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # initialize the maximum value of F(k) to be the initial value of F(0)
        max_val = sum(i * nums[i] for i in range(len(nums)))
        # initialize the sum of all elements in nums
        total_sum = sum(nums)
        # initialize the current value of F(k) to be the initial value of F(0)
        curr_val = max_val
        # iterate over the possible values of k
        for k in range(1, len(nums)):
            # update the current value of F(k)
            curr_val = curr_val + total_sum - len(nums) * nums[-k]
            # update the maximum value of F(k) if necessary
            max_val = max(max_val, curr_val)
        return max_val
