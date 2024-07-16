class Solution {
public:
    string to_int(string s){
        for(int i = 0; i < s.size(); i++){
            s[i] = s[i] - 'a' + '0';
        }
        return s;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        firstWord = to_int(firstWord);
        secondWord = to_int(secondWord);
        targetWord = to_int(targetWord);
        return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
    }
};