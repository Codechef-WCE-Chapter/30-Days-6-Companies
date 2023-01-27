#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
// #define ll long long int
using namespace std;
class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if (s.size() < k)
        {
            return false;
        }
        set<string> s1;
        for (int i = 0; i < s.size() - k + 1; i++)
        {
            s1.insert(s.substr(i, k));
        }
        return s1.size() == pow(2, k);
    }
};

int main()
{
    Solution s;
    cout << "ans:" << s.hasAllCodes("00110110", 2);
}