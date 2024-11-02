class Solution {
public:
    string int_to_str(int x){
        string s;
        while(x > 0){
            s += (char)('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    bool queryString(string s, int n) {
        for(int i = 1; i <= n; i++){
            if(s.find(int_to_str(i)) == -1){
                return false;
            }
        }
        return true;
    }
};