class Solution {
public:
    string countAndSay(int n) {
        string st = "1";
        for(int i = 1; i < n; i++){
            string tmp = "";
            int cnt = 1;
            char now = st[0];
            for(int j = 1; j < st.size(); j++){
                if(st[j] == now){
                    cnt++;
                }
                else{
                    tmp += (to_string(cnt) + now);
                    cnt = 1;
                    now = st[j];
                }
            }
            tmp += (to_string(cnt) + now);
            st = tmp;
        }
        return st;
    }
};