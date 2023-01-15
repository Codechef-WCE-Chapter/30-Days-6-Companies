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
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        int n = cards.size();
        for (int i = 0; i < n; i++)
        {
            int val = cards[i];
            if (mp.find(val) == mp.end())
            {
                mp[val] = i;
                //    cout<<"puted:"<<val<<endl;
            }
            else
            {
                ans = min(ans, i - mp[val]);
                //    cout<<"i:"<<i<<"  "<<"prevI:"<<mp[val]<<endl;
                //    cout<<"ans:"<<ans<<endl;
                mp[val] = i;
            }
        }
        if (ans == INT_MAX)
            return -1;
        return ans + 1;
    }
};
int main()
{
    vector<int> cards{3, 4, 2, 3, 4, 7};
    Solution s;
    cout << s.minimumCardPickup(cards) << endl;
}