class Solution {
public:
    long long ans=0;
    void mergeSortedArray(vector<int>& arr,int start,int end,int diff){
        int mid=start+(end-start)/2;
        int l=start,r=mid+1;
        while(l<=mid&&r<=end){
            if(arr[l]<=arr[r]+diff){
                ans+=(end-r+1);
                l++;
            }
            else{
                r++;
            }
        }
        sort(arr.begin()+start,arr.begin()+end+1);
    }
    void mergeSort(vector<int>& arr,int start,int end,int diff){
        if(start==end) return;
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid,diff);
        mergeSort(arr,mid+1,end,diff);
        mergeSortedArray(arr,start,end,diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int> vec;
        for(int j=0;j<n;j++){
            int curr=nums1[j]-nums2[j];
            vec.push_back(curr);
        }
        mergeSort(vec,0,n-1,diff);
        return ans;
    }
};