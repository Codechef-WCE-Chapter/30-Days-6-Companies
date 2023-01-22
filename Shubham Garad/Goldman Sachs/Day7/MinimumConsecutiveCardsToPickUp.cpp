class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

       int n = cards.size();
       int mini = INT_MAX;
       unordered_map<int,int>mp;
       for(int i = 0;i<n;++i)
       {
            if(mp.find(cards[i]) ==mp.end())
            {
                mp[cards[i]] =i;
            }
            else
            {
                mini = min(mini,i-mp[cards[i]]+1);
                mp[cards[i]] =i;
            }
       } 
       if(mini == INT_MAX)
       {
           return -1;
       }
       return mini;
    }
};