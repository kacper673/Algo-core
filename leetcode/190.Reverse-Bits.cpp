class Solution {
public:
    int reverseBits(int n) {
        string bin = "";
        bin.reserve(32);
        int counter = 1;
        while(n > 0){
        counter++;
        int bit = n%2;
        bin.push_back('0' + bit);
        n/=2;
        }
        while(counter <= 32){
            bin.push_back('0');
            counter++;
        }
    
        int num = 0;
        for(int i = 0; i < 32; i++){
            num+= ((bin[i] - '0') * pow(2,31-i));
        }
       
    return num;
    }
};
