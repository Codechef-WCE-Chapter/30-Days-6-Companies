from collections import Counter
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        counts = Counter(secret)
        a,b = 0,0
        for s,g in zip(secret, guess):
            if s == g: 
                a += 1
                if counts[s]: counts[s] -= 1
                else: b -= 1
            elif counts[g]:
                b += 1
                counts[g] -= 1
        return f"{a}A{b}B"