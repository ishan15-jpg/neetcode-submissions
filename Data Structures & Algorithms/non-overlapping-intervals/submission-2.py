class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda interval : interval[-1])
        res = 1
        end = intervals[0][1]
        for i in range(len(intervals)):
            if intervals[i][0] >= end:
                end = intervals[i][-1]
                res += 1
        return len(intervals) - res