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

// -------meth1------
class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {

        sort(special.begin(), special.end());

        int ans = max((special[0] - bottom), (top - special[special.size() - 1]));
        int count = 0;

        for (int i = 0; i < special.size() - 1; i++)
        {
            count = special[i + 1] - special[i] - 1;
            ans = max(count, ans);
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr{7, 6, 8};
    int btm = 6, top = 8;
    cout << s.maxConsecutive(btm, top, arr) << endl;
}