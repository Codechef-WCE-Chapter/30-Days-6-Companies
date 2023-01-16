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

int ans = INT_MIN;
vector<int> tempp;

void recur(int i, int t, vector<int> &arr, int temp, vector<int> &anss)
{
    if ((i < 0 && t >= 0) || t == 0)
    {
        if (ans < max(ans, temp))
        {
            for (int j = 0; j < 12; j++)
                tempp[j] = anss[j];

            // IF ALL THE ARROWS ARE NOT USED
            tempp[0] += t;
        }

        ans = max(ans, temp);

        return;
    }

    else if (i < 0)
        return;

    // TAKE
    if (t >= arr[i])
    {
        anss[i] = arr[i] + 1;

        recur(i - 1, (t - arr[i] - 1), arr, temp + i, anss);
        anss[i] = 0;
    }

    // LEAVE
    recur(i - 1, t, arr, temp, anss);
}

vector<int> maximumBobPoints(int t, vector<int> &arr)
{
    tempp.resize(12, 0);
    vector<int> anss(12, 0);
    recur(11, t, arr, 0, anss);

    return tempp;
}
int main()
{
    int t = 3;
    vector<int> arr{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2};
    vector<int> ans = maximumBobPoints(t, arr);
    for (auto val : ans)
        cout << val << " ";
}