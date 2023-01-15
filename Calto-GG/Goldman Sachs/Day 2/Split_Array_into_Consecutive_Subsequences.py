from collections import Counter

# A bit tricky to proceed with.. initialize the counter to get the frequency 
# of the numbers occuring and dont need to sort here since they are already sorted
# in Counter cause of input is already sorted next we play with pointers inside the 
# dictionay of counter. Time Complexity is O(set(N)^2)
# but its memory efficient no extra stuff required besides the counter dict. 

class Solution:
    def isPossible(self, nums: list[int]) -> bool:
        counter = Counter(nums)
        for i in counter.keys():
            while counter[i] > 0:
                last = 0
                j = i
                k = 0
                while counter[j] >= last:
                    last = counter[j]
                    counter[j] -= 1
                    j += 1
                    k += 1
                if k < 3:
                    return False
        return True