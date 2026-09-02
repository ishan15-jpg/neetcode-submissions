class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adjList = { c: set() for w in words for c in w }
        for i in range(len(words)-1):
            str1,str2 = words[i],words[i+1]
            if len(str1) > len(str2) and str1.startswith(str2): return ""
            for j in range(len(str1)):
                if str1[j] != str2[j]:
                    adjList[str1[j]].add(str2[j])
                    break
        visited = set()
        trace = set()
        res = []
        def dfs(l: str) -> bool:
            visited.add(l)
            trace.add(l)
            for neigh in adjList[l]:
                if neigh in trace: return True
                if neigh not in visited and dfs(neigh): return True
            res.append(l)
            trace.remove(l)
            return False
        for c in adjList:
            if c not in visited and dfs(c): return ""
        return "".join(reversed(res))