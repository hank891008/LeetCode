class Solution {
public:
    string arrangeWords(string text) {
        stringstream ss(text);
        string s;
        vector<string> v;
        while(getline(ss, s, ' ')){
            v.emplace_back(char(tolower(s[0])) + s.substr(1));
        }
        stable_sort(v.begin(), v.end(), [](string a, string b){
            return a.size() < b.size();
        });
        string ans;
        for(int i = 0; i < v.size(); i++){
            if(i){
                ans += ' ';
            }
            ans += v[i];
        }
        ans[0] = toupper(ans[0]);
        return ans;
    }
};