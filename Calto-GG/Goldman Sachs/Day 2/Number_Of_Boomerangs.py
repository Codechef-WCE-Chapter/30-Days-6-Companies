#  For each point, we create a dictionary (cmap) to store the number of points 
# that are a certain distance away from the current point. The distance is 
# calculated using the difference in x and y coordinates, and stored as the key 
# in the dictionary.
# Then we iterate over the dictionary, and for each key, we calculate the 
# number of boomerangs that can be formed using the value of the key, 
# which is the number of points that are that distance away.
# Finally we return the total number of boomerangs.

class solution:
    def numberOfBoomerangs(self, points: list[list[int]]) -> int:
        res = 0
        # Iterate through each point in the input list
        for p in points:
            cmap = {}
            # calculate distance from current point 'p' to all other points
            for q in points:
                # calculate difference in x and y coordinates
                f = p[0]-q[0]
                s = p[1]-q[1]
                # store distance as key in dictionary, and increase count by 1
                cmap[f*f + s*s] = 1 + cmap.get(f*f + s*s, 0)
            # Iterate through the dictionary
            for k in cmap:
                # calculate number of boomerangs that can be formed using the value of the key
                res += cmap[k] * (cmap[k] -1)
        return res