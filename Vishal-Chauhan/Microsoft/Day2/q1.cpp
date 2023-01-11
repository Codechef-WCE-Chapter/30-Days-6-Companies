#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ------------meth1--------------O(n^2)
// int max(int a, int b)
// {
//     return a > b ? a : b;
// }
int maxRotateFunction2(vector<int> &num)
{
    int n = num.size();
    int r = 0;
    int i = 0;
    int ans = INT_MIN;
    while (i < n)
    {
        int temp = 0;
        int j = 0;
        while (j < n)
        {
            temp += (num[r] * j);
            // cout<<"num:"<<num[(r+1+n)%n]<<"  temp:"<<temp<<"  |";
            j++;
            r = (r + 1 + n) % n;
        }
        // cout<<"ans:"<<ans<<endl;
        ans = max(temp, ans);
        r = (r - 1 + n) % n;
        i++;
    }
    return ans;
}

// ----------------meth2----------------O(n)-->DP
int maxRotateFunction(vector<int> &num)
{
    int n = num.size();
    vector<int> ans(n, INT_MIN);
    int val0 = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        val0 += (num[i] * i);
        sum += num[i];
    }
    ans[0] = val0;
    int got = ans[0];
    // cout<<"ans:"<<got<<"  ";
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] + sum - n * num[n - i];
        // cout<<ans[i]<<"  ";
        got = max(got, ans[i]);
    }
    return got;
}
int main()
{
    vector<int> arr{4, 3, 2, 6};
    cout << maxRotateFunction(arr) << endl;
    cout << maxRotateFunction2(arr) << endl;

    return 0;
}
