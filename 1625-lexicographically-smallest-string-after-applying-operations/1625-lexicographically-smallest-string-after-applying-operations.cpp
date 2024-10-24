class Solution {
public:
    void dfs(string s, int a, int b, set<string>& check){
        string s1, s2;
        check.insert(s);
        for(int i = 0; i < s.size(); i++){
            if(i % 2 == 1){
                s1 += (((s[i] - '0') + a) % 10) + '0';
            }
            else{
                s1 += s[i];
            }
        }
        s2 = s.substr(b) + s.substr(0, b);
        if(!check.count(s1)){
            dfs(s1, a, b, check);
        }
        if(!check.count(s2)){
            dfs(s2, a, b, check);
        }
    }
    string findLexSmallestString(string s, int a, int b) {
        set<string> check;
        dfs(s, a, b, check);
        return *check.begin();
    }
};