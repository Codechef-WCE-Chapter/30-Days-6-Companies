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
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        int n = price.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += price[i] * needs[i];
        }
        for (auto offer : special)
        {
            bool valid = true;
            for (int i = 0; i < n; i++)
            {
                if (offer[i] > needs[i])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                for (int i = 0; i < n; i++)
                {
                    needs[i] -= offer[i];
                }
                res = min(res, offer[n] + shoppingOffers(price, special, needs));
                for (int i = 0; i < n; i++)
                {
                    needs[i] += offer[i];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> price = {2, 3, 4};
    vector<vector<int>> special = {{1, 1, 0, 4}, {2, 2, 1, 9}};
    vector<int> needs = {1, 2, 1};
    cout << s.shoppingOffers(price, special, needs) << endl;
}