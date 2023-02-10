#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
// method1

// class Solution {
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string,int> mp;
//         for(auto str:words){
//             mp[str]++;
//         }
//         vector<string> ans;
//         priority_queue<pair<int,string>> pq;
//         for(auto val:mp){
//             pq.push({val.second,val.first});
//         }
//         vector<string> temp;
//         int prev_val=0;
//         while(k--){
//             // ans.push_back({pq.top().second});pq.pop();
//             if(temp.size()==0)
//             {
//                 prev_val=pq.top().first;
//                 temp.push_back({pq.top().second});pq.pop();
//             }
//             else if(pq.top().first==prev_val){
//                 temp.push_back({pq.top().second});pq.pop();
//             }
//             else{
//                 sort(temp.begin(),temp.end());
//                 for(auto val:temp){
//                     ans.push_back(val);
//                 }
//                 temp.erase(temp.begin(),temp.end());

//                 prev_val=pq.top().first;
//                 temp.push_back({pq.top().second});pq.pop();
//             }

//         }
//         sort(temp.begin(),temp.end());
//         for(auto val:temp){
//             ans.push_back(val);
//         }
//         return ans;
//     }
// };

// meth2
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        for (auto str : words)
        {
            mp[str]++;
        }
        vector<pair<int, string>> vec;
        for (auto val : mp)
        {
            vec.push_back({-val.second, val.first});
        }
        sort(vec.begin(), vec.end());
        vector<string> ans;
        for (int i = 0; i < vec.size() && k > 0; i++)
        {
            ans.push_back(vec[i].second);
            k--;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<string> words{"is", "is", "Dog", "is", "Animal", "is", "Dog"};
    int k = 2;
    vector<string> ans = s.topKFrequent(words, k);
    for (auto val : ans)
        cout << val << " ";
}