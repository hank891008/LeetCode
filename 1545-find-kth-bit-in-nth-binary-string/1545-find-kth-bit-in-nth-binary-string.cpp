class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 2; i <= n; i++){
            string tmp = s;
            for(int j = 0; j < tmp.size(); j++){
                if(tmp[j] == '1'){
                    tmp[j] = '0';
                }
                else{
                    tmp[j] = '1';
                }
            }
            reverse(tmp.begin(), tmp.end());
            s = s + "1" + tmp;
            // cout << s << '\n';
        }
        return s[k - 1];
    }
};