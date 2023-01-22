// Using resursive method Day 1 (Recursion)
class Solution {
public:
    int addDigits(int num) {
        long sum=0;
        while(num > 0){
            sum+=num%10;
            num=num/10;
        }
        if(sum <= 9){
            return sum;
        }
        return addDigits(sum);
    }
};