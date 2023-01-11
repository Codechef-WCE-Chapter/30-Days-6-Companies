// Absolute Explaination 
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> m;
    
        for(auto r : rectangles) {
            
            // We will add the coordinates of left bottom corner and top right corner
            // We will also subtract the top left corner and bottom right corner
            m[{r[0], r[1]}]++;
            m[{r[2], r[3]}]++;
            m[{r[0], r[3]}]--;
            m[{r[2], r[1]}]--;
            
            // When the number of points become zero, we will remove the points
            
            if(m[{r[0], r[3]}] == 0) m.erase({r[0], r[3]});
            if(m[{r[2], r[1]}] == 0) m.erase({r[2], r[1]});
            if(m[{r[0], r[1]}] == 0) m.erase({r[0], r[1]});
            if(m[{r[2], r[3]}] == 0) m.erase({r[2], r[3]});
            
        }
        
        // Now, the points remaining in the map will be the corners, so if there are less than or more than 4 cornersm, answer will be false
        
        if(m.size() != 4) return false;
        
        // If two rectangle overlaps, still we are suppose to return false, so we are checking whether all points are 1 or not
        for(auto i : m) {
            if(abs(i.second) != 1) return false;
        }
        
        return true;
        
    }
};
