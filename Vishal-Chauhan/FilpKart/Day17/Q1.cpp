#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        int i = 0;
        while (v.size() != 1)
        {
            i = (i + k - 1) % (v.size());
            // cout<<v[i]<<endl;
            v.erase(v.begin() + i);
        }
        return v[0];
    }
};
int main()
{
    Solution s;
    cout << s.findTheWinner(8, 3) << endl;
}