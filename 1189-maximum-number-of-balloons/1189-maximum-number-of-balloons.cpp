class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string balloon = "balloon";
        unordered_map<char, int> m;
        m['b'] = 0;
        m['a'] = 0;
        m['l'] = 0;
        m['o'] = 0;
        m['n'] = 0;
        for(int i = 0; i < text.size(); i++){
            if(balloon.find(text[i]) != string::npos){
                m[text[i]]++;
            }
        }
        m['l'] /= 2;
        m['o'] /= 2;
        int minn = INT_MAX;
        for(auto it: m){
            minn = min(minn, it.second);
        }
        return minn;
    }
};