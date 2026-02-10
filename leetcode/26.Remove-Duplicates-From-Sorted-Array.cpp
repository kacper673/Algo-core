class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int k = 1;
        
        int n = nums.size();
        int last_num = nums[0];
        std::vector<int> unique;
        unique.push_back(last_num);
        for(int i = 0; i<n; i++){
            if(nums[i] != last_num){
                k++;
                last_num = nums[i];
                unique.push_back(last_num);
            }
             
        }
        for(int i  =0; i < unique.size(); i++){
            cout<<unique[i];
            nums[i] = unique[i];

        }
        cout<<k;
        return k;
    }
};
