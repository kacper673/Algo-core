class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0].empty()) return "";
        int longest_prefix = strs[0].size();
        string str = strs[0];
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].size() < longest_prefix){
                longest_prefix = strs[i].size();
            }
            for(int j = longest_prefix; j >= 0; --j){
                if(strs[i][j] != str[j]) longest_prefix =j;
            }
        }
        if(longest_prefix == 0) return "";
        return str.substr(0,longest_prefix);
    }
};
