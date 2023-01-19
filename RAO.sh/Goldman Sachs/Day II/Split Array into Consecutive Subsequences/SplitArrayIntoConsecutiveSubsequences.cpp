class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> Freq;
        unordered_map<int, int> Need;

        for(int i=0; i<nums.size(); i++) Freq[nums[i]]++;
        
        for(auto n : nums){
            if(!Freq[n]) continue;
            Freq[n]--;

            if(Need[n]){
                Need[n]--;
                Need[n+1]++;
            }
            else if(Freq[n+1] && Freq[n+2]){
                Freq[n+1]--;
                Freq[n+2]--;
                Need[n+3]++;
            }
            else return false;
        }

        return true;
    }
};
