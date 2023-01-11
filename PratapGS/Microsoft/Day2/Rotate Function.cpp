class Solution {
public:
 int maxRotateFunction(vector<int>& nums) {
    //  if(nums.size() ==1 || nums.size() == 0){
    //         return 0;
    //     }


     
long sum =0,curr =0;


for(int i =0; i <nums.size(); i++){
    sum += nums[i];
    curr += i*nums[i];
}



long res = curr;
int n = nums.size();

for(int i = n-1; i >=0; i--){
    curr += sum -(nums[i]*n);
    res = max(curr,res);
}

return res;
 }


/*

//Brute Force Approach O(N^2)
int rotate(vector<int> & nums, int n)
{
    int sum =0;
    int x = nums[n - 1], i;
    for (i = n - 1; i > 0; i--){
        nums[i] = nums[i - 1];
        sum += i * nums[i];
    }
    nums[0] = x;

    return sum;
}
 

    int maxRotateFunction(vector<int>& nums) {

        vector<int> res;
        if(nums.size() ==1 || nums.size() == 0){
            return 0;
        }
        else{
            for(int i =0; i< nums.size(); i++){
                
                res.push_back(rotate(nums,nums.size()));

            }
        }
        sort(res.begin(), res.end(), greater<int>());

        return res[0];
    }
    */
};
