class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        size_t n = stones.size();

        priority_queue<int> pq;

        for(int i=0; i<n; i++) pq.push(stones[i]);

        while(pq.size() > 1){
            int top1 = pq.top(); pq.pop();
            int top2 = pq.top(); pq.pop();

            pq.push(abs(top1-top2));
        }

        int answer = pq.top(); pq.pop();

        return answer;
    }
};
