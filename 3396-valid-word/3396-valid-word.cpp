class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3){
            return false;
        }
        bool vowel = false, consonant = false;
        for(auto c: word){
            if(!isalpha(c) && !isdigit(c)){
                return false;
            }
            else if(isdigit(c)){
                continue;
            }
            c = tolower(c);
            if(string("aeiou").find(c) != -1){
                vowel = true;
            }
            else{
                consonant = true;
            }
        }
        return vowel && consonant;
    }
};