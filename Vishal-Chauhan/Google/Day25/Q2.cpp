#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool palindrome(string &s)
    {
        int p = 0;
        int q = s.size() - 1;
        while (p < q)
        {
            if (s[p] == s[q])
            {
                p++;
                q--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i <= n - 2; i++)
        {
            int p = n;
            string s;
            while (p > 0)
            {
                s.push_back(p % i);
                p /= i;
            }
            if (!palindrome(s))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
}