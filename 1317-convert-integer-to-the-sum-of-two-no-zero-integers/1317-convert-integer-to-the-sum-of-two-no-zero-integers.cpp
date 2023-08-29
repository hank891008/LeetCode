class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            string a = to_string(i);
            string b = to_string(n - i);
            if(count(a.begin(), a.end(), '0') == 0 && count(b.begin(), b.end(), '0') == 0){
                return {i, n - i};
            }
        }
        return {0, n};
    }
};