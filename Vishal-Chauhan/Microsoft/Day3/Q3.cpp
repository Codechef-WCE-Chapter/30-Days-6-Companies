#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <math.h>
#include <algorithm>
#include <map>
#define ll long long int
using namespace std;
// -----------getting somewhere wrong------------
long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
{
    long long ans = 0;
    unordered_map<int, int> hashmap;
    for (int num : nums1)
    {
        hashmap[num]++;
    }
    for (int num : nums2)
    {
        ans += hashmap[num + diff];
    }
    return ans;
}

int main()
{
    vector<int> a{3, -1}, b{-2, 2};
    int diff = -1;
    cout << numberOfPairs(a, b, diff) << endl;
}