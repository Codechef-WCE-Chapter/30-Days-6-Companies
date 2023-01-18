class Solution {
public:
    int rev(int n) {
    int res = 0;
    for (; n > 0; n /= 10)
        res = res * 10 + n % 10;
    return res;
}


int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> m;
    int res = 0;
    for (auto n : nums)
        res = (res + m[n - rev(n)]++) % 1000000007;
    return res;
}
