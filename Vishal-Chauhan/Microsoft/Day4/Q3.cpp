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
using namespace std;
class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.size();
        vector<int> prefix(n, 0);
        int i = 0, j = 1;
        while (j < n)
        {
            if (s[i] == s[j])
            {
                prefix[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if (i == 0)
                {
                    j++;
                }
                else
                {
                    i = prefix[i - 1];
                }
            }
        }

        return s.substr(0, i);
    }
};
int main()
{
    string str = "ababab";
    string str2 = "level";
    Solution s;
    cout << "logest prefix is:" << s.longestPrefix(str) << endl;
    cout << "logest prefix is:" << s.longestPrefix(str2);
}