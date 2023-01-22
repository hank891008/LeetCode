class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ret = pref;
        for(int i = 1; i < ret.size(); i++){
            ret[i] ^= pref[i - 1];
        }
        return ret;
    }
};