#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
#define inf 11111111111
using namespace std;
class Solution
{
public:
#define ll long long int
    ll a = 1e10, b = 1e10;
    bool increasingTriplet(vector<int> &nums)
    {

        for (int i : nums)
        {
            if (i > b)
                return true;
            if (i > a)
                b = min((long long)i, b);
            a = min((ll)i, a);
        }
        return false;
    }
};
int main()
{
    vector<int> arr{12, 56, 34, 35};
    Solution s;
    cout << s.increasingTriplet(arr) << endl;
}