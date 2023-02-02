#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    class subClass
    {
    public:
        unordered_map<int, subClass *> next;
        int c;
        subClass()
        {
        }
    };
    int countDistinct(vector<int> &nums, int k, int p)
    {
        subClass *root = new subClass();
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            // Temp Pointer, which copies the root.
            subClass *temp = root;

            // Count stores total number divisible by 'P' so far.
            int count = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] % p == 0)
                    count++;

                // If count is greater than 'K' we do not have valid subarray.
                if (count > k)
                    break;
                if (!temp->next[nums[j]])
                {
                    temp->next[nums[j]] = new subClass();
                    ans++;
                }
                temp = temp->next[nums[j]];
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    cout << "ans:" << s.countDistinct(nums, 4, 1) << endl;
}