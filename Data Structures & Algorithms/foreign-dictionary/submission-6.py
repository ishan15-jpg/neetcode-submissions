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
        state = { c: 0 for c in adjList.keys() }
        res = []
        def dfs(l: str) -> bool:
            if state[l]: return True if state[l] == 1 else False
            state[l] = 1
            for neigh in adjList[l]:
                if dfs(neigh): return True
            res.append(l)
            state[l] = 2
            return False
        for c in adjList:
            if dfs(c): return ""
        return "".join(reversed(res))