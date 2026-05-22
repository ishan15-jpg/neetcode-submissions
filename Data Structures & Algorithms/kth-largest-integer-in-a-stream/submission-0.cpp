class KthLargest {
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(const int num : nums) this->pq.push(num);
    }
    
    int add(int val) {
        this->pq.push(val);
        vector<int> temp;

        for(int i=0; i<this->k-1; i++){
            temp.push_back(this->pq.top());
            this->pq.pop();
        }

        int kthTop = this->pq.top();

        for(int i=0; i<this->k-1; i++){
            this->pq.push(temp[i]);
        }

        return kthTop;
    }
};
