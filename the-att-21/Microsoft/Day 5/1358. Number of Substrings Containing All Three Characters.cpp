* Problem : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

* Solution : 

class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> f;
        int n = size(s) - 1;
        int left = 0, right = 0, ans = 0;
        
        while(right < size(s)){
            f[s[right]]++;

            if(size(f) < 3){ right++; }

            if(size(f) == 3){
                while(size(f) == 3){
                    ans += (1 + n - right);
                    f[s[left]]--;

                    if(f[s[left]] == 0) { f.erase(s[left]); }
                    left++;
                }
                right++;
            }
        }

        return ans;
    }
};