class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& arr) {
        map<int, int> mp;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        sort(arr.begin(), arr.end());
        
        for(auto it: mp){
            int p=0;
            for(int i=0; i<arr.size(); i++){
                if(arr[i]%it.first!=0){
                    p=1;
                    break;
                }
            }
            if(p==1){
                ans+=it.second;
            }
            else{
                return ans;
            }
        }
        return -1;
    }
};
