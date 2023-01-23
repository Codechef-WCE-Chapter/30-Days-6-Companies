#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define ll long long int
using namespace std;
class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> bank_set(bank.begin(), bank.end());
        if (!bank_set.count(end))
        {
            return -1;
        }
        queue<string> q{{start}};
        int level = 0;
        unordered_set<string> seen{start};
        while (!q.empty())
        {
            for (int i = q.size(); i > 0; --i)
            {
                auto gene = q.front();
                q.pop();
                if (gene == end)
                {
                    return level;
                }
                for (int j = 0; j < 8; ++j)
                {
                    for (auto c : "ACGT")
                    {
                        auto new_gene = gene;
                        new_gene[j] = c;
                        if (!seen.count(new_gene) && bank_set.count(new_gene))
                        {
                            q.push(new_gene);
                            seen.insert(new_gene);
                        }
                    }
                }
            }
            ++level;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    // cout<<s.minMutation();
}