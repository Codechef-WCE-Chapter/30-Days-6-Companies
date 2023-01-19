class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> M;
        int ans = INT_MAX;

        for(int i=0; i<cards.size(); i++){
            if(M.find(cards[i]) != M.end()){
                ans = min(ans, i - M[cards[i]] + 1);
            }

            M[cards[i]] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
