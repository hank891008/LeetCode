class Solution {
public:
    int getLucky(string s, int k) {
        string num_st;
        int num;
        for(auto w: s){
            num_st += to_string(w - 'a' + 1);
        }
        for(int i = 0; i < k; i++){
            num = 0;
            for(int j = 0; j < num_st.size(); j++){
                num += num_st[j] - '0';
            }
            num_st = to_string(num);
        }
        return num;
    }
};