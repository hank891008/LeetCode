class Solution {
public:
    struct Item{
        string code;
        int order;
        bool isActive;
        bool operator<(const Item& rhs) const {
            return order < rhs.order || (order == rhs.order && code < rhs.code);
        }
    };
    bool valid_code(string code) {
        for(auto c: code) {
            if(!isalpha(c) && !isdigit(c) && c != '_') {
                return false;
            }
        }
        return code.size() > 0;
    }
    int valid_business(string business) {
        if( business == "electronics") {
            return 1;
        }
        else if( business == "grocery") {
            return 2;
        }
        else if( business == "pharmacy") {
            return 3;
        }
        else if( business == "restaurant") {
            return 4;
        }
        return -1;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> ans;
        vector<Item> valid;
        for(int i = 0; i < n; i++) {
            if(valid_code(code[i]) && valid_business(businessLine[i]) > 0 && isActive[i]) {
                valid.emplace_back(code[i], valid_business(businessLine[i]));
            }
        }
        sort(valid.begin(), valid.end());
        for(auto v: valid) {
            ans.emplace_back(v.code);
        }
        return ans;
    }
};