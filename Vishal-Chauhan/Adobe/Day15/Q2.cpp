#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
#define MOD 1000000007;
using namespace std;

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        ll i = 2;
        vector<vector<ll>> person = {{1 + delay, 1 + forget, 1}}; // startOfSpread,forgetDay,countOfPpl
        while (i <= n)
        {
            while (!person.empty() && person[0][1] == i)
            {
                person.erase(person.begin());
            }
            ll cnt = 0;
            for (auto val : person)
            {
                if (val[0] <= i)
                {
                    cnt += val[2];
                }
                cnt %= MOD;
            }
            person.push_back({i + delay, i + forget, cnt});
            i++;
        }
        ll ans = 0;
        for (auto val : person)
        {
            ans += val[2];
            ans %= MOD;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    cout << "ans:" << s.peopleAwareOfSecret(6, 2, 4) << endl;
}