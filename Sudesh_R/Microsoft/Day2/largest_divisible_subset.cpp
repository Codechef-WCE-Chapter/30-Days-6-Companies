class Solution
{
public:
    //  to store largest divisible subset
    vector<int> ans;
    int dp[100005];

    void lds(vector<int> temp, int i, int prev, vector<int> &nums)
    {
        // Base case: if all elements are processed
        if (i >= nums.size())
        {
            // update ans if current subset is larger than previous
            if (temp.size() > ans.size())
                ans = temp;
            return;
        }

        // Check if current element is divisible by previous element
        // if current subset size is greater than previous
        if ((int)temp.size() > dp[i] && (nums[i] % prev == 0))
        {
            dp[i] = temp.size();
            // add current element to subset
            temp.push_back(nums[i]);
            // recursive call with updated subset and previous element
            lds(temp, i + 1, nums[i], nums);
            temp.pop_back();
        }
        // recursive call without adding current element to subset
        lds(temp, i + 1, prev, nums);
    }

    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // sort the input array
        sort(nums.begin(), nums.end());
        // fill the dp array with -1
        memset(dp, -1, sizeof(dp));
        // initialize an empty subset
        vector<int> temp;
        lds(temp, 0, 1, nums);
        return ans;
    }
};