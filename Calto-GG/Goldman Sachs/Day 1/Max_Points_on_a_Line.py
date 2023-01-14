#Primitive approach with O(N^3) complexity

from itertools import combinations
class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        ll = len(points) 
        if ll == 1: return 1
        elif ll == 2: return 2
        else:
            ans = 0
            for i in list(combinations(points,2)):
                cnt = 0
                for j in points:
                    if (j[1] - i[0][1]) * (i[1][0] - i[0][0]) == (j[0] - i[0][0]) * (i[1][1] - i[0][1]):
                        cnt += 1
                ans = max(ans, cnt)
            return ans

#In the below version, we have two loops. The outer loop iterates over all the 
#points which is O(n) and the inner loop iterates over all the points except 
# the current point which is O(n-1) and O(n-1) = O(n) so the total time
# complexity is O(n*n) = O(n^2)
class Solution(object):
    def maxPoints(self, points):
        if len(points) < 3:
            return len(points)
        max_points = 0
        for i in range(len(points)):
            slopes = {}
            duplicate = 0
            for j in range(i+1, len(points)):
                x1, y1 = points[i]
                x2, y2 = points[j]
                if x1 == x2:
                    if y1 == y2:
                        duplicate += 1
                    else:
                        slope = "inf"
                else:
                    slope = 1.0 * (y2-y1) / (x2-x1)
                if slope in slopes:
                    slopes[slope] += 1
                else:
                    slopes[slope] = 1
                max_points = max(max_points, max(slopes.values()) + duplicate + 1)
        return max_points