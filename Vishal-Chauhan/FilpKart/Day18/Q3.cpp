#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
#include <map>
#define ll long long int
using namespace std;
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freq;
        for (string word : words)
        {
            freq[word]++;
        }
        auto cmp = [&](string a, string b)
        {
            if (freq[a] != freq[b])
            {
                return freq[a] > freq[b];
            }
            return a < b;
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for (auto &[word, count] : freq)
        {
            if (pq.size() < k)
            {
                pq.push(word);
            }
            else if (cmp(word, pq.top()))
            {
                pq.pop();
                pq.push(word);
            }
        }
        vector<string> res;
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> arr{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> ans = s.topKFrequent(arr, 4);
    for (auto val : ans)
        cout << val << " ";
}