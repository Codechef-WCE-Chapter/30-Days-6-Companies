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
    int numberOfSubstrings(string s)
    {
        int a_index = -1;

        int b_index = -1;

        int c_index = -1;

        int result = 0;

        for (int index = 0; index < s.size(); index++)
        {

            if (s[index] == 'a')
                a_index = index;
            if (s[index] == 'b')
                b_index = index;
            if (s[index] == 'c')
                c_index = index;
            if (index > 1)
                result += std::min({a_index, b_index, c_index}) + 1;
        }
        return result;
    }
};
int main()
{
    Solution s;
    string str = "abcabc";
    cout << s.numberOfSubstrings(str) << endl;
}