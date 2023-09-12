class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>Set;
        int ans = 1;
        for(int i = 0; i < s.size(); i++){
            if(Set.count(s[i])){
                Set.clear();
                ans++;
            }
            Set.insert(s[i]);
        }
        return ans;
    }
};