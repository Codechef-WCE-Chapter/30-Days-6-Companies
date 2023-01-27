#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
// #define ll long long int
using namespace std;

class Solution
{
    typedef long long ll;
#define vi(x) vector<x>
public:
    vi(bool) primes;
    void setPrimes(ll n)
    {
        primes.assign(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (ll i = 2; i * i <= n; i++)
        {
            if (primes[i])
            {
                for (ll j = i; j * i <= n; ++j)
                {
                    primes[j * i] = 0;
                }
            }
        }
    }
    vector<int> closestPrimes(int l, int r)
    {
        setPrimes(r);
        ll pre = -1; // prev encountered prime number
        vi(int) ans = {-1, -1};
        for (ll i = l; i <= r; ++i)
        {
            if (!primes[i])
            {
                continue;
            }
            if (pre > -1 && (ans[0] == -1 || i - pre < ans[1] - ans[0]))
            {
                ans = {int(pre), int(i)};
            }
            pre = i;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> ans = s.closestPrimes(2, 8);
    for (auto val : ans)
        cout << val << "  ";
    cout << endl;
}