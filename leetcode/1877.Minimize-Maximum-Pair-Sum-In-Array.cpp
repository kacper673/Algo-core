class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> pairs_sum;
        int n = nums.size();

        for(int i = 0; i < n/2; i++){
            pairs_sum.push_back(nums[i] + nums[n - 1 - i]);
        }
        
        return *max_element(pairs_sum.begin(),pairs_sum.end());
    }
};
