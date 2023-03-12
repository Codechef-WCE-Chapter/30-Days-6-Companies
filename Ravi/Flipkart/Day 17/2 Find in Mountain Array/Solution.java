/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        
        int n = mountainArr.length();
        int low = 0, high = n - 1;
        
        int ans = -1;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(mid == 0) {
                low = mid + 1;
                continue;
            } 
            
            if(mid == n - 1) break;
            
            int mide = mountainArr.get(mid);
            int prev = mountainArr.get(mid - 1);
            int next = mountainArr.get(mid + 1);
            
            if(mide > prev && mide > next) {
                ans = mid;
                break;
            }
            
            if(mide < next) low = mid + 1;
            else high = mid - 1;
            
        }
        
        
        low = 0;
        high = ans;
        
        // System.out.println(mountainArr.get(ans));
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            int mide = mountainArr.get(mid);
            if(mide == target) return mid;
            
            if(mide < target) low = mid + 1;
            else high = mid - 1;
            
        }
        
        low = ans + 1;
        high = n - 1;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            int mide = mountainArr.get(mid);
            if(mide == target) return mid;
            
            if(mide > target) low = mid + 1;
            else high = mid - 1;
            
        }
        
        return -1;
        
    }
}
