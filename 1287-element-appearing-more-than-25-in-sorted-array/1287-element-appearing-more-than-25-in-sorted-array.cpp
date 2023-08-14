class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int>m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
            if((double)m[arr[i]] / arr.size() > 0.25){
                return arr[i];
            }
        }
        return -1;
    }
};