class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto l: letters){
            if(l > target){
                return l;
            }
        }
        return letters[0];
    }
};