class Solution {
public:
    int josephus(int n, int k){
    return n > 1 ? (josephus(n - 1, k) + k) % n : 0;
    }
    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1;
    }
};