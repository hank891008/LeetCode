class Solution {
public:
    bool dp(int idx, vector<int>& bits){
        if(idx < 0){
            return true;
        }
        bool ret = false;
        if(bits[idx] == 0){
            ret |= dp(idx - 1, bits);
        }
        if(idx >= 1 && bits[idx - 1] == 1){
            ret |= dp(idx - 2, bits);
        }
        return ret;
    }
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1){
            return true;
        }
        return dp((int)bits.size() - 2, bits); 
    }
};