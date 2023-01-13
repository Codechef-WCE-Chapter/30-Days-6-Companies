* Problem : https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

* Solution : 

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int ans = 0, help = numsDivide[0], n = size(nums);

        sort(begin(nums), end(nums));
        for(int i = 1; i < size(numsDivide); i++){
            help = __gcd(numsDivide[i], help);
        }
        cout<<help;
        for(int i = 0; i < size(nums); i++){
            if(help % nums[i] == 0) { break; }
            ans++;
        }

        return ans == n? -1 : ans;
    }
};