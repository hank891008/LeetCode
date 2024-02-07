class Solution {
public:
    struct item{
        char alpha;
        int cnt = 0;
        bool operator<(const item& rhs)const{
            return cnt > rhs.cnt;
        }
    };
    string frequencySort(string s) {
        vector<item> v(62);
        for(int i = 0; i < 26; i++){
            v[i].alpha = 'a' + i;
            v[i + 26].alpha = 'A' + i;
        }
        for(int i = 0; i < 10; i++){
            v[i + 52].alpha = '0' + i;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z')
                v[s[i] - 'a'].cnt++;
            else if(s[i] >= 'A' && s[i] <= 'Z')
                v[s[i] - 'A' + 26].cnt++;
            else
                v[s[i] - '0' + 52].cnt++;
        }
        sort(v.begin(), v.end());
        string ans;
        for(int i = 0; i < 62; i++){
            if(v[i].cnt == 0){
                break;
            }
            for(int j = 0; j < v[i].cnt; j++){
                ans += v[i].alpha;
            }
        }
        return ans;
    }
};