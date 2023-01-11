class Solution(object):
    def isRectangleCover(self, rectangles):
        # Set to store the corners of the rectangles
        corner = set()
        # Initialize variables to keep track of the top-left and bottom-right points
        # of the rectangular region formed by the rectangles
        a, b, c, d, area = float('inf'), float('inf'), float('-inf'), float('-inf'), 0
        # Iterate through the rectangles
        for x1, y1, x2, y2 in rectangles:
            # Update the top-left point if necessary
            if x1 <= a and y1 <= b:
                a, b = x1, y1
            # Update the bottom-right point if necessary
            if x2 >= c and y2 >= d:
                c, d = x2, y2
            # Add the points to the set and update the area
            corner ^= {(x1, y1), (x2, y2), (x1, y2), (x2, y1)}
            area += (x2 - x1) * (y2 - y1)
        # Check if the set of corners is equal to the expected set
        # and if the area is equal to the area of the rectangular region
        return corner == {(a, b), (c, d), (a, d), (c, b)} and area == (c - a) * (d - b)
