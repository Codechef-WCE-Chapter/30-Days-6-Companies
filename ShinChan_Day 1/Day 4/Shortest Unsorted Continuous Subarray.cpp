class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), p=-1, q=-1;
        vector<int> nums1;
        for(int i=0; i<n; i++){
            nums1.push_back(nums[i]);
        }
        sort(nums1.begin(), nums1.end());
        if(n>1){
            for(int i=0; i<n; i++){
                if(nums[i]!= nums1[i]){
                    p= (i);
                    break;
                }
            }
            for(int i=n-1; i>=0; i--){
                if(nums[i]!=nums1[i]){
                    q=(i);
                    break;
                }
            }
            cout<<p<<" "<<q;
            if(p==-1 || q==-1) return 0;
            else return (q-p)+1;
        }
        return 0;
    }
};
