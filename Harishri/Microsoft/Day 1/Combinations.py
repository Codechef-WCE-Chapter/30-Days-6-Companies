class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        nums = [i for i in range(1,10)]
        comb = itertools.combinations(nums,k)
        return [c for c in comb if sum(c) == n]
