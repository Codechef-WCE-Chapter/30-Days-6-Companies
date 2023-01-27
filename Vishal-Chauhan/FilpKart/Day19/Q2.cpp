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
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k == 0 || n >= k + maxPts - 1)
            return 1.0;
        vector<double> dp(n + 1);
        dp[0] = 1.0;
        double W = 1.0, res = 0.0;
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = W / maxPts;
            if (i < k)
                W += dp[i];
            else
                res += dp[i];
            if (i - maxPts >= 0)
                W -= dp[i - maxPts];
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << "myans:" << s.new21Game(10, 3, 15) << endl;
}