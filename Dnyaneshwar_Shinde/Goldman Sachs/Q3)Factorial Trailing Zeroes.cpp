// https: // leetcode.com/problems/factorial-trailing-zeroes/description/

// Given an integer n, return the number of trailing zeroes in n

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {

        int ans = 0;
        while (n > 0)
        {
            ans += (n / 5);
            n = n / 5;
        }
        return ans;
    }
};

int32_t main()
{

    return 0;
}