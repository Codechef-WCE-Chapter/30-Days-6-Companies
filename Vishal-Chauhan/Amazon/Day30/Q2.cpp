#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        int maxAns = INT_MIN;
        for (auto val : right)
        {
            maxAns = max(maxAns, n - val);
        }
        for (auto val : left)
        {
            maxAns = max(maxAns, val);
        }
        return maxAns;
    }
};

int main()
{
    Solution s;
    int n = 4;
    vector<int> left{4, 3}, right{0, 1};
    cout << "ans:" << s.getLastMoment(n, left, right);
}