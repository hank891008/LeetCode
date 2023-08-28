class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string st = to_string(n);
        sort(st.begin(), st.end());
        do{
            if(st[0] == '0'){
                continue;
            }
            else{
                if(__builtin_popcount(stoi(st)) == 1){
                    return true;
                }
            }
        }while(next_permutation(st.begin(), st.end()));
        return false;
    }
};