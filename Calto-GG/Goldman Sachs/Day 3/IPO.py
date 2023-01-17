# First we sort the projects by their capital requirements in ascending order. 
# Then, use a while loop to iterate over the sorted projects and add the 
# most profitable projects (with capital requirements less than or equal to 
# the current available capital) to a heap. Finally, we repeatedly select the 
# most profitable project from the heap (up to k times) and subtract the project's 
# profit from the current capital until the heap is empty or k projects have been 
# selected. The final capital is returned as the result.

# heapq is used to implement the priority queue. The negative sign before 
# the project's profit is used to make the heap work as a max heap.

import heapq
class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        projects = sorted(zip(profits, capital), key=lambda x: x[1])
        heap = []
        i = 0
        for _ in range(k):
            while i < len(projects) and projects[i][1] <= w:
                heapq.heappush(heap, -projects[i][0])
                i += 1
            if heap:
                w -= heapq.heappop(heap)
        return w

