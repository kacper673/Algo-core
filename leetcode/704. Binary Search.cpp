class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = nums.size();
        int left = 0;
        int right = mid - 1;
        mid /=2;
        while(left <= right){
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) right = mid -1;
        else if(nums[mid] < target) left = mid + 1;
        mid = left + ((right-left)/2);
        }

        return -1;
    }
};

