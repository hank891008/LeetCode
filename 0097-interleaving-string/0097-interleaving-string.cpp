class Solution {
public:
    map<pair<string, string>, bool>m;
    bool dfs(string s1, string s2, string s3){
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        if(s1.size() == 0 || s2.size() == 0){
            return s1 == s3 || s2 == s3;
        }
        if(m.count({s1, s2})){
            return m[{s1, s2}];
        }
        bool result = false;
        if(s1[0] == s3[0]){
            result |= dfs(s1.substr(1), s2, s3.substr(1));
        }
        if(s2[0] == s3[0]){
            result |= dfs(s1, s2.substr(1), s3.substr(1));
        }
        return m[{s1, s2}] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        return dfs(s1, s2, s3);
    }
};