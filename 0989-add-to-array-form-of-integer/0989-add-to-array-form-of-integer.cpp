class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(int i = 0; i < to_string(k).size(); i++){
            num.insert(num.begin(), 0);
        }
        for(int i = num.size() - 1; i >= 0; i--){
            num[i] += k % 10;
            k /= 10;
            if(num[i] >= 10 && i != 0){
                num[i - 1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        if(num[0] >= 10){
            num.insert(num.begin(), num[0] / 10);
            num[1] %= 10;
        }
        while(num[0] == 0){
            num.erase(num.begin());
        }
        return num;
    }
};