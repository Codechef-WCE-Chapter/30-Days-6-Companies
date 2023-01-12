class Solution(object):
    def isRectangleCover(self, rectangles):
        hs = set()
        area = 0
        for rec in rectangles:
            top_left = (rec[0], rec[1])
            top_right = (rec[0], rec[3])
            bottom_left = (rec[2], rec[1])
            bottom_right = (rec[2], rec[3])
            area += (rec[2] - rec[0]) * (rec[3] - rec[1])
            for i in [top_left, top_right, bottom_left, bottom_right]:
                if i not in hs:
                    # print(hs,1)
                    hs.add(i)
                else:
                    hs.remove(i)
                    # print(hs,0)
        if len(hs) != 4:
            return False
        hs = sorted(hs)
        # print(hs)
        first = hs.pop(0)
        last = hs.pop()
        print(first,last)
        return area == (last[0] - first[0]) * (last[1] - first[1])
