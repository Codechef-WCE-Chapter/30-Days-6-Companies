class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        lst1 = list(secret)
        lst2 = list(guess)
        x = 0
        for i in range(len(lst2)):
            if lst1[i] == lst2[i]:
                x += 1
        y = len(lst1) - sum((Counter(lst1) - Counter(lst2)).values()) - x
        res = ''.join(str(x)+'A'+str(y)+'B')
        return res
