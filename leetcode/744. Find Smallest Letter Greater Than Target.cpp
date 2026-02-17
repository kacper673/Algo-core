class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        int n = letters.size();
        while(i < n){
            if(letters[i] > target) return letters[i];
            i++;
        }
        return letters[0];
    }
};
