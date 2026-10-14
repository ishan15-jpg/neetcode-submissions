class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        n = len(intervals)
        intervals.sort(key=lambda interval : interval[0])
        i = 1
        while i < len(intervals):
            if intervals[i][0] <= intervals[i-1][1]:
                intervals[i-1][0] = min(intervals[i-1][0],intervals[i][0])
                intervals[i-1][1] = max(intervals[i-1][1],intervals[i][1])
                intervals.remove(intervals[i])
            else: i += 1
        return intervals