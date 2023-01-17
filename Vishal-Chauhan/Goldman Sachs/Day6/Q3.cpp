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
#define inf 11111111111
using namespace std;

int trailingZeroes(int n)
{
    int ans = 0;
    //    ans+=(n/5);
    int j = 1;
    for (int i = 5; i <= n;)
    {
        int x = i;
        while (x % 5 == 0)
        {
            x /= 5;
            ans++;
        }
        j++;
        i = 5 * j;
    }

    return ans;
}
int main()
{
    vector<int> arr{3, 5, 9, 10, 14, 15, 19, 20, 23, 25, 26, 28, 29, 30};
    for (auto val : arr)
        cout << "for:" << val << "  trailing zeroes:" << trailingZeroes(val) << endl;
}