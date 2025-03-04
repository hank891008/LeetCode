class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss1(sentence1), ss2(sentence2);
        string tmp;
        deque<string> dq1, dq2;
        while(ss1 >> tmp){
            dq1.emplace_back(tmp);
        }
        while(ss2 >> tmp){
            dq2.emplace_back(tmp);
        }
        while(!dq1.empty() && !dq2.empty() && (dq1.front() == dq2.front())){
            dq1.pop_front();
            dq2.pop_front();
        }
        while(!dq1.empty() && !dq2.empty() && (dq1.back() == dq2.back())){
            dq1.pop_back();
            dq2.pop_back();
        }
        return dq1.empty() || dq2.empty();
    }
};