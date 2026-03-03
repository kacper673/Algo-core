class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_height = 0;
        int n = height.size();
        int i = 0;
        int j = n - 1;
        
        while(i < j){
            int tmp = min(height[i],height[j]) * (j - i);
            if(tmp > max_height) max_height = tmp;
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return max_height;
    }
};
