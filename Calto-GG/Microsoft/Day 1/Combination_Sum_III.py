class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        res=[]
        def recurse(i=0,c=1,r=[],s=0):
            if i==k:
                if s==n:
                    res.append(r[:])
            if i>=k or c>9:
                return
            r.append(c)
            recurse(i+1,c+1,r,s+c)
            r.pop()
            recurse(i,c+1,r,s)
            
        recurse()
        return res