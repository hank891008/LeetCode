class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>s;
        int idx = 0, ret = 0;
        while(idx < (int)height.size()){
            if(s.empty() || height[idx] <= height[s.top()]){
                s.emplace(idx);
                idx += 1;
            }
            else{
                int t = s.top();
                s.pop();
                if(s.empty()){
                    continue;
                }
                ret += (min(height[idx], height[s.top()]) - height[t]) * (idx - s.top() - 1);
            }
        }
        return ret;
    }
};