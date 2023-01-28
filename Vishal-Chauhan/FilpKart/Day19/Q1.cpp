#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include<queue>
#include <cmath>
#include <algorithm>
#include <map>
// #define ll long long int
using namespace std;
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        vector<int> result;
        unordered_map<int, int> freq;
        for (auto elem : barcodes)
        {
            freq[elem]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto it : freq)
        {
            pq.push({it.second, it.first});
        }
        int prev = -1;
        while (!pq.empty())
        {
            if (prev == pq.top().second)
            {
                // Case 1st
                pair<int, int> pair1 = pq.top();
                pq.pop();
                pair<int, int> pair2 = pq.top();
                result.push_back(pair2.second);
                pq.pop();
                pair2.first--;
                // if it gets zero means no more element to consider so only adding back to max-heap when freq>0
                if (pair2.first > 0)
                {
                    pq.push({pair2.first, pair2.second});
                }
                pq.push(pair1);
                prev = pair2.second;
            }
            else
            // Case 2nd
            {
                pair<int, int> pair1 = pq.top();
                pq.pop();
                prev = pair1.second;
                result.push_back(pair1.second);
                pair1.first--;
                // if it gets zero means no more element to consider so only adding back to max-heap when freq>0
                if (pair1.first > 0)
                {
                    pq.push({pair1.first, pair1.second});
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> barcode{1, 3, 2, 5, 3, 2, 1, 1, 2, 3, 2, 1, 2, 3, 5, 2, 5};
    vector<int> ans = s.rearrangeBarcodes(barcode);
    for (auto val : ans)
        cout << val << " ";
}