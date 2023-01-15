// https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

// Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
// All subsequences have a length of 3 or more.

// Algo
//  - take 2 maps m and m1
//  - if m[nums[i]] nahi hai to frequency kam karo
//  - check karo nums[i]-1 present hai kya m1 map mai
//  - agar hai to uski frequency m1 se kam karo and m1[nums[i]]++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> m, m1;
        for (auto i : nums)
        {
            m[i]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] != 0)
            {
                m[nums[i]]--;
                if (m1[nums[i] - 1] > 0)
                {
                    m1[nums[i] - 1]--;
                    m1[nums[i]]++;
                }
                else
                {
                    if (m[nums[i] + 1] != 0 and m[nums[i] + 2] != 0)
                    {
                        m[nums[i] + 1]--;
                        m[nums[i] + 2]--;
                        m1[nums[i] + 2]++;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int32_t main()
{

    return 0;
}