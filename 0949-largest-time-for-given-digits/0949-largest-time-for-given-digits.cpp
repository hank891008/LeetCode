class Solution {
public:
    bool valid(vector<int> arr){
        int h = 10 * arr[0] + arr[1];
        int m = 10 * arr[2] + arr[3];
        return h >= 0 && h < 24 && m >= 0 && m < 60;
    }
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), greater<int>());
        do{
            if(valid(arr)){
                string ret;
                ret += to_string(arr[0]);
                ret += to_string(arr[1]);
                ret += ':';
                ret += to_string(arr[2]);
                ret += to_string(arr[3]);
                return ret;
            }
        }while(prev_permutation(arr.begin(), arr.end()));
        return "";
    }
};