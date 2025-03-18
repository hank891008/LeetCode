class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        while(carry){
            int next_carry = (sum & carry) << 1;
            sum ^= carry;
            carry = next_carry;
        }
        return sum;
    }
};