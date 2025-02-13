class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        stringstream ss(text);
        string s;
        vector<string> v;
        while(getline(ss, s, ' ')){
            v.emplace_back(s);
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