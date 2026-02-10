class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> solution(2);
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){ solution[0] = i; solution[1] = j; } 
            }
        }
        return solution;
    }
};
