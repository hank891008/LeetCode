class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bit(32, 0);
        for(auto c: candidates){
            for(int i = 0; i < 32 && c > 0; i++){
                bit[i] += c & 1;
                c >>= 1;
            }
        }
        return *max_element(bit.begin(), bit.end());
    }
};