class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int window = 0;
        int window2 = 0;
        bool can_increase = true;
        while (can_increase) {
            can_increase = false;
            while (j < nums.size() - 1 && nums[j] <= (long long)nums[i] * k) {
                if (j - i + 1 > window2)
                    window2 = j - i + 1;
                std::cout << nums[j] << " ";
                j++;
                can_increase = true;
            }

            while (i < nums.size() - 1 && nums[j] > (long long)nums[i] * k) {
                i++;
                can_increase = true;
            }
        }
        window = j - i + 1;
        return window > window2 ? (nums.size() - window)
                                : (nums.size() - window2);
    }
};
