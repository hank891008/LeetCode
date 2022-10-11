class Solution {
public:
    static bool cmp(int a, int b){
        string aa = to_string(a);
        string bb = to_string(b);
        return (aa + bb) >= (bb + aa);
    }
    string largestNumber(vector<int>& nums) {
        int flag = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                flag++;
            }
        }
        if(flag == 0){
            return "0";
        }
        string ret;
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++){
            ret += to_string(nums[i]);
        }
        return ret;
    }
};