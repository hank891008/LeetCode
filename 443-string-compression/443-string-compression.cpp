class Solution {
public:
    int compress(vector<char>& chars) {
        int ret = 0;
        char now = chars[0];
        int cnt = 1;
        vector<char>v;
        for(int i = 1; i < chars.size(); i++){
            if(chars[i] != now){
                v.emplace_back(now);
                if(cnt == 1){
                    ret += 1;
                }
                else{
                    ret += (1 + to_string(cnt).size());
                    stack<int>s;
                    while(cnt != 0){
                        s.emplace(cnt % 10);
                        cnt /= 10;
                    }
                    while(!s.empty()){
                        cout << s.top() << '\n';
                        v.emplace_back(s.top() + '0');
                        s.pop();
                    }
                }
                cnt = 1;
                now = chars[i];
            }
            else{
                cnt++;
            }
        }
        v.emplace_back(now);
        if(cnt == 1){
            ret += 1;
        }
        else{
            ret += (1 + to_string(cnt).size());
            stack<int>s;
            while(cnt != 0){
                s.emplace(cnt % 10);
                cnt /= 10;
            }
            while(!s.empty()){
                v.emplace_back(s.top() + '0');
                s.pop();
            }
        }
        for(auto i: v){
            cout << i << ' ';
        }
        chars = v;
        return ret;
    }
};