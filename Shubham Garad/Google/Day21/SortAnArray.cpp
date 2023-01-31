class Solution {
public:

    void Merge(vector<int> &nums, int low, int mid, int high) 
    {
	    if (low >= high)
        {
            return ;
        }

	    int l = low, r = mid + 1, k = 0, size = high - low + 1;

	    vector<int> sorted(size, 0);

	    while (l <= mid && r <= high)
        {
		    sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        }
	    while (l <= mid) 
		{
            sorted[k++] = nums[l++];
        }    
	    while (r <= high)
        {
		    sorted[k++] = nums[r++];
        }

	    for (k = 0; k < size; k++)
        {
		    nums[k + low] = sorted[k];
        }
    }

    void mergeSort(vector<int> &nums, int low, int high) 
    {
	    if (low >= high)
        {
            return;
        }

	    int mid = (high - low) / 2 + low;

	    mergeSort(nums, low, mid);
	    mergeSort(nums, mid + 1, high);
	    Merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        int low =0;
        int high = n-1;
        mergeSort(nums ,low ,high);
        return nums;
    }
};