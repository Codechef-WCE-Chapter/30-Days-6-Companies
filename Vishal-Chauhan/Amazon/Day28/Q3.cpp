#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        vector<vector<string>> ans;
        unordered_map<string, long long> m;
        vector<pair<pair<long long, string>, string>> v;
        long long mx = -1;
        int n = ids.size();
        for (int i = 0; i < n; ++i)
        {
            v.push_back({{views[i], ids[i]}, creators[i]});
            m[creators[i]] += views[i];
            mx = max(mx, m[creators[i]]);
        }
        sort(begin(v), end(v), [](pair<pair<long long, string>, string> &a, pair<pair<long long, string>, string> &b)
             {if(a.first.first == b.first.first) return a < b; return a > b; });
        unordered_set<string> st;
        for (auto &_v : v)
        {
            if (m[_v.second] != mx)
                continue;
            if (st.count(_v.second))
                continue;
            st.insert(_v.second);
            ans.push_back({_v.second, _v.first.second});
        }
        return ans;
    }
};

int main()
{
    Solution s;
}