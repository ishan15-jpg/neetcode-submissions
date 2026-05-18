class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();

        set<vector<int>> st;

        for(int i=0; i<n-2; i++)
        for(int j=i+1; j<n-1; j++)
        for(int k=j+1; k<n; k++){
            if(nums[i]+nums[j]+nums[k] == 0){ 
                vector<int> temp{nums[i], nums[j], nums[k]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }

        if(st.empty()) return {};

        return {st.begin(),st.end()};
    }
};
