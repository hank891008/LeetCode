/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* head;

public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    int getRandom() {
        int cnt = 1;
        ListNode* curr = this->head;
        int chosen;
        while(curr != NULL){
            float r = (float)rand() / RAND_MAX;
            cout << r << ' ' << 1.0 / cnt << '\n';
            if(r < 1.0 / cnt){
                chosen = curr->val;
            }
            cnt += 1;
            curr = curr->next;
        }
        return chosen;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */