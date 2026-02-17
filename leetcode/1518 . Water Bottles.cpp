class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottles_drunk = 0;
        int empty_bottles = 0;

        while(numBottles > 0 || numExchange <= empty_bottles){
            if(numBottles > 0){
                //printf("Drunk %d bottles \n",numBottles);
                bottles_drunk += numBottles;
                empty_bottles += numBottles;
                numBottles -= numBottles;
            }
            else{
                int new_bottles = empty_bottles/numExchange;
                empty_bottles -= new_bottles*numExchange;
                //printf("Empty bottles after exhchange %d \n",empty_bottles);
                numBottles += new_bottles;
            }
        }
        return bottles_drunk;
    }
};
