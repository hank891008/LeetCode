class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string st;
        int idx = 1;
        while(ss >> st){
            if(st.find(searchWord) == 0){
                return idx;
            }
            idx++;
        }
        return -1;
    }
};