class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        if(name[0] != typed[0]){
            return false;
        }
        while(j < typed.size()){
            if(name[i] == typed[j]){
                i++;
            }
            else if(i > 0 && name[i - 1] != typed[j]){
                return false;
            }
            j++;
        }
        return i == name.size();
    }
};