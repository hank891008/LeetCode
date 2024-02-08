class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string>s;
        sort(words.begin(), words.end());
        string ret;
        int maxx = 0;
        for(auto w: words){
            if(w.size() == 1 || s.count(w.substr(0, w.size() - 1))){
                if(w.size() > maxx){
                    maxx = w.size();
                    ret = w;
                }
                s.insert(w);
            }
        }
        return ret;
    }
};