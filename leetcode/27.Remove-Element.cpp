class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int n = nums.size();
        int j = 1;
        for(int i = 0; i < n; i++){
            int temp;
            if(nums[i] == val){
                while(n-j > i && nums[n-j] == val){ j++; 
                }
                if (n - j <= i) { 
                    k++; 
                    continue; 
                }
                nums[i] = nums[n-j];
                j++;
                k++;
            }
        }
        return n - k;
    }
};
