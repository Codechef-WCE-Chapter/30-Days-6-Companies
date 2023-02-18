class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        set<vector<int>> hs;
        
        for(int i = 0; i < nums.size(); i++) {
            
            vector<int> curr;
            
            int count = 0;
            for(int j = i; j < nums.size(); j++) {
                curr.push_back(nums[j]);
                if(nums[j] % p == 0) count++;
                if(count <= k) hs.insert(curr);
            }
            
        }
        return hs.size();
        
    }
};
