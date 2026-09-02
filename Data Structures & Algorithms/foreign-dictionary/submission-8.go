func dfs(c byte, state map[byte]int, answer *[]byte, adjList map[byte]map[byte]bool) bool {
    if state[c] == 1 { return true }
    if state[c] == 2 { return false }
    state[c] = 1
    for neigh := range adjList[c] {
        if dfs(neigh, state, answer, adjList) { return true }
    }
    *answer = append(*answer,c)
    state[c] = 2
    return false
}

func min(a,b int) int {
    if a < b { return a }
    return b
}

func reverse(s []byte) {
    for i,j:=0,len(s)-1; i<j; i,j=i+1,j-1 {
        s[i],s[j] = s[j],s[i]
    }
}

func foreignDictionary(words []string) string {
    adjList := make(map[byte]map[byte]bool)
    for _,word := range words {
        for i:=0; i<len(word); i++ {
            c := word[i]
            if _,exists := adjList[c]; !exists {
                adjList[c] = make(map[byte]bool)
            }
        }
    }
    for i:=0; i<len(words)-1; i++ {
        word1 := words[i]
        word2 := words[i+1]
        minLen := min(len(word1),len(word2))
        if len(word1) > len(word2) && word1[:minLen] == word2[:minLen] { return "" }
        for j:=0; j<minLen; j++ {
            if word1[j] != word2[j] {
                adjList[word1[j]][word2[j]] = true
                break
            }
        }
    }
    state := make(map[byte]int)
    answer := []byte{}
    for c := range adjList {
        if dfs(c,state,&answer,adjList) { return "" }
    }
    reverse(answer)
    return string(answer)
}
