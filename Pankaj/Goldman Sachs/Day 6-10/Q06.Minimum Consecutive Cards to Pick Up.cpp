class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        map<int,int> mp;
        int res=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(cards[i])==mp.end()){
                mp[cards[i]]=i;
            }
            else{
                res=min(res,i-mp[cards[i]]+1);
                mp[cards[i]]=i;
            }
        }
        return res==INT_MAX?-1:res;
    }
};