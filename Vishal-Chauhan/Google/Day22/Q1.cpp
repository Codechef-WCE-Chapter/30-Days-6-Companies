#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> count;
        int res = 0, i = 0;
        for (int j = 0; j < fruits.size(); j++)
        {
            count[fruits[j]]++;
            while (count.size() > 2)
            {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0)
                    count.erase(fruits[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> fruits{2, 3, 5, 4, 6};
    cout << s.totalFruit(fruits) << endl;
}