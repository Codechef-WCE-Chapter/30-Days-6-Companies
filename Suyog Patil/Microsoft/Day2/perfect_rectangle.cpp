
#define pii pair<int, int>

class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &r)
    {
        int n = r.size();
        map<pii, int> mp;
        for (vector<int> vv : r)
        {
            mp[{vv[0], vv[1]}]++;
            mp[{vv[2], vv[3]}]++;
            mp[{vv[0], vv[3]}]--;
            mp[{vv[2], vv[1]}]--;
        }

        int ans = 0;
        for (auto it : mp)
            ans += abs(it.second);

        return (ans == 4);
    }
};
