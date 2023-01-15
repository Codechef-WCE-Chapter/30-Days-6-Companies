
# Simple intuative approach -> Just check for the keys and value of length in 
# dictionary and have an array for multiple keys and return its minimun 
class Solution:
    def minimumCardPickup(self, cards: list[int]) -> int:
        dic = {}
        lengths = []
        for i,j in enumerate(cards):
            if j in dic:
                lengths.append(abs(dic[j]-i)+1)
                dic[j]=i
            else:
                dic[j]=i
        if len(lengths)>0:
            return min(lengths)
        else:
            return -1