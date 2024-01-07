class Solution {
public:
    char repeatedCharacter(string s) {
        set<char>Set;
        for(int i = 0; i < s.size(); i++){
            if(Set.count(s[i])){
                return s[i];
            }
            Set.insert(s[i]);
        }
        return ' ';
    }
};