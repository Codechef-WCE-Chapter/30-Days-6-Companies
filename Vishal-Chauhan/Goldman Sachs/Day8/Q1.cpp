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
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < profits.size(); i++)
            arr.push_back({capital[i], profits[i]});
        sort(arr.begin(), arr.end());

        priority_queue<int> q;
        int ans = 0, i = 0;
        while (i < arr.size() and k)
        {
            if (w >= arr[i].first)
                q.push(arr[i++].second);
            else
            {
                // This condition will check if we had enough capital to choose any project or not. If not, we directly return the current capital.
                if (q.empty())
                    return w;

                w += q.top();
                q.pop();
                k--;
            }
        }
        // Here, we check if we could still choose some projects
        while (k-- and !q.empty())
        {
            w += q.top();
            q.pop();
        }
        return w;
    }
};

int main()
{
    Solution s;
    int k = 3, w = 0;
    vector<int> profit{1, 2, 3}, capital{0, 1, 2};
    cout << s.findMaximizedCapital(k, w, profit, capital) << endl;
}