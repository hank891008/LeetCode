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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        auto now = head;
        vector<int>v;
        int len = 0;
        while(now != nullptr){
            v.emplace_back(now -> val);
            now = now -> next;
            len += 1;
        }
        cout << len << '\n';
        auto tmp = v;
        for(int i = 0; i < tmp.size(); i++){
            tmp[(i + k) % len] = v[i];
        }
        v = tmp;
        now = new ListNode(v[0]);
        auto prev = now;
        for(int i = 1; i < v.size(); i++){
            ListNode* tmp = new ListNode(v[i]);
            prev -> next = tmp;
            prev = tmp;
        }
        return now;
    }
};