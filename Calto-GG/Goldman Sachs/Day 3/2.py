# First, we create a map for the elements in the second list, so that we can 
# quickly find the position of each element in the second list using its value 
# as a key.

# Then, for each element in the first list, we find the position of the element 
# in the second list using the map, and using bisect.bisect function to find the 
# position of that element in the second list. The bisect.bisect function returns 
# the index of the first element in the list that is greater than or equal to the 
# element we are looking for. we also insert that element into a list called "q"
# The idx variable will hold the position of the inserted element in the "q" list.

# The next step is to count the number of good triplets for each element in the 
# first list. A good triplet is a triplet that is increasing in both lists.

# The number of good triplets for each element in the first list can be calculated 
# by counting the number of elements that are smaller than the current element in 
# both lists.

# By using the idx variable and the length of the first list, we can calculate the 
# number of elements that are smaller than the current element in the second list.

# The number of elements that are smaller than the current element in the first 
# list can be calculated by subtracting the current element's index in the 
# first list and the position of the current element in the second list.

# The final step is to add up the number of good triplets for all elements 
# in the first list and return the result.

# It is an O(n log n) solution as the bisect.bisect function uses a binary search 
# which is O(log n) and the rest of the operations are O(n)
import bisect
class Solution(object):
    def goodTriplets(self, nums1, nums2):
        n = len(nums1)
        res = 0
        m2 = [0] * n
        q = []
		# Build index map of nums2
        for i in range(n):
            m2[nums2[i]] = i
        for p1 in range(n):
            p2 = m2[nums1[p1]] # Position of nums1[p1] in nums2
            idx = bisect.bisect(q, p2) # Position smaller than this one so far
            q.insert(idx, p2)
            before = idx
            after = n-1 - p1 - p2 + before # Based on number of unique values before and after are the same
            res += before * after
        return res