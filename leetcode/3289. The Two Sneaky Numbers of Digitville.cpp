class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> seen(100,0);
        int sneaky_count = 0;
        vector<int> sneaky;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if(sneaky_count > 1) return sneaky;
            if (seen[nums[i]] > 0) {
                sneaky.push_back(nums[i]);
                sneaky_count++;
            }
            seen[nums[i]]++;
        }
        return sneaky;
    }
};

