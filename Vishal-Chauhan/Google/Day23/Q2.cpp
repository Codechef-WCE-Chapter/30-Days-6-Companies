
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> w;
    Solution(vector<int> &w)
    {
        // Prefix sum
        for (int i = 1; i < w.size(); i++)
        {
            w[i] = w[i] + w[i - 1];
        }
        this->w = w;
    }

    int pickIndex()
    {
        int hi = w.back();
        int index = rand() % hi;
        index++;
        int lower = lower_bound(w.begin(), w.end(), index) - w.begin();
        return lower;
    }
};

int main()
{
    vector<int> w = {1, 2, 3};
    Solution s(w);
    cout << "ans:" << s.pickIndex() << endl;
    for (auto val : w)
    {
        cout << "wi:" << val << endl;
    }
}