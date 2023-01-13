class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if (nums.size() == 0) return 0;

		long long allsum = 0;
		long long sum2 = 0;
		for (int i = 0; i < nums.size(); i++) {
			allsum += nums[i] * i;
			sum2 += nums[i];
		}

		long long result = allsum;
		for (int i = 0; i < nums.size(); i++) {
			allsum -= sum2;
			allsum += nums[i];
			allsum += nums[i] * int(nums.size() - 1);
			result = max(allsum, result);
		}

		return result;
    }
};