"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        pq = []
        intervals.sort(key=lambda interval : interval.start)
        for interval in intervals:
            if pq:
                previous = heapq.heappop(pq)
                if interval.start < previous:
                    heapq.heappush(pq,previous)    
                heapq.heappush(pq,interval.end)
            else:
                heapq.heappush(pq,interval.end)
        return len(pq)