# We use a sliding window approach to find the number of substrings containing 
# at least one occurrence of all characters 'a', 'b' and 'c'.
# we maintain a count of the number of occurrences of each of the characters 'a', 'b' and 'c' in 
# the current window. Also maintain two pointers, i and j, which represent the start 
# and end of the current window respectively.

# The function iterates through the string and for each character, it increases the count 
# of that character. If the count of all three characters 'a', 'b' and 'c' is greater than zero, 
# it means that the current window contains all three characters, so the function increments 
# the answer by the current value of i, which represents the start of the current window. 
# Then the function starts to move the start pointer i to right by decreasing the count of 
# the character at index i, until the count of one of the characters becomes zero.
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        count = [0] * 3
        ans = i = 0
        for j in range(len(s)):
            count[ord(s[j]) - ord('a')] += 1
            while all(count):
                count[ord(s[i]) - ord('a')] -= 1
                i += 1
            ans += i
        return ans

