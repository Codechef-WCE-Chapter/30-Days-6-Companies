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
    bool asteroidsDestroyed(int mass, vector<int> &a)
    {
        sort(a.begin(), a.end());
        long long int sum = mass;
        for (auto val : a)
        {
            if (sum < val)
                return false;
            sum += val;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> ast{3, 6, 1, 2, 4};
    cout << "ans:" << s.asteroidsDestroyed(10, ast);
}