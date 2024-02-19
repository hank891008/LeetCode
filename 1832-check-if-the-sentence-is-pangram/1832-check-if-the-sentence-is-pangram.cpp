class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;
        for(int i = 0; i < 26; i++){
            s.insert('a' + i);
        }
        for(int i = 0; i < sentence.size(); i++){
            s.erase(sentence[i]);
            if(s.size() == 0){
                return true;
            }
        }
        return s.size() == 0;
    }
};