#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int distinctEchoSubstrings(string s)
    {
        int mod = INT_MAX, base = 28, n = s.size();
        unordered_map<long long, int> um;
        vector<long long> ChkVal(n + 1);
        long long remove = 1;
        for (int i = 1; i <= n / 2; i++)
        {
            long long hash = 0;
            int l = 0, appear = 0;
            for (int j = 0; j < n; j++)
            {
                hash = ((hash * base) % mod + (s[j] - 'a' + 1)) % mod;
                if (j - l == i - 1)
                {
                    ChkVal[j] = hash;
                    if (appear > 0)
                    {
                        if (ChkVal[j - i] == hash)
                            um[hash]++;
                    }
                    appear++;
                    hash = (hash - ((s[l] - 'a' + 1) * remove) % mod) % mod;
                    if (hash < 0)
                        hash += mod;
                    l++;
                }
            }
            // cout << i << " " << um.size() << endl;
            remove = (remove * base) % mod;
        }
        return um.size();
    }
};

int main()
{
    Solution s;
}