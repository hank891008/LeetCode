class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        arr.emplace_back(0);
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i - 1] + 1){
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr.back();
    }
};