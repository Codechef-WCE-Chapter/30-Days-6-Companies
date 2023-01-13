class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v=nums;
        sort(v.begin(), v.end());
        int s=0, e=v.size()-1;
        while(s<=v.size()-1 && v[s]==nums[s]){
            s++;
        }
        while(e>=0 && v[e]==nums[e]){
            e--;
        }
        cout<<s<<" "<<e;
        if(e<0 || s>v.size()-1){return 0;}
        return e-s+1;
    }
};