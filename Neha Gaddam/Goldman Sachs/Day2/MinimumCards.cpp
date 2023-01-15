class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>back;
        int ans=INT_MAX;
        int i=0,j=cards.size()-1;
        while(i<=j)
        {
            if(back.find(cards[i])!=back.end())
                ans=min(ans,(i-back[cards[i]]+1));
           
            back[cards[i]]=i;
            
            i++;
        
        }
       
    return (ans==INT_MAX)?-1:ans;
    }
};