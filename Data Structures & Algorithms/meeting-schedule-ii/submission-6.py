"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        intervals.sort(key=lambda interval : interval.start)
        pq = []
        for interval in intervals:
            if pq:
                end = heapq.heappop(pq)
                if interval.start < end:
                    heapq.heappush(pq,end)
                heapq.heappush(pq,interval.end)
            else:
                heapq.heappush(pq,interval.end)
        return len(pq)
