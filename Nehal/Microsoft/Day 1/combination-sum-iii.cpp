class Solution
{
public:
    vector<vector<int>> ans;
    void recur(int idx, int target, int k, vector<int> arr)
    {

        if (target == 0)
        {
            if (arr.size() == k)
                ans.emplace_back(arr);
            return;
        }

        for (int i = idx; i <= 9; i++)
        {

            // if(i>idx && nums[i]==nums[i-1]) continue;
            if (i > target || arr.size() == k)
                break;
            arr.emplace_back(i);
            recur(i + 1, target - i, k, arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        recur(1, n, k, {});
        return ans;
    }
};