class Solution {
public:
    int partitionString(string s) {
        set<char>Set;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(!Set.count(s[i])){
                Set.insert(s[i]);
            }
            else{
                Set.clear();
                Set.insert(s[i]);
                ans++;
            }
        }
        if(!s.empty()){
            ans++;
        }
        return ans;
    }
};