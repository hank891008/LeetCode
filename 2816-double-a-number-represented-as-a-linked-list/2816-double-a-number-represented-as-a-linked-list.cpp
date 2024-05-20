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
    
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> s;
        ListNode* now = head;
        while(now){
            s.emplace(now);
            now = now->next;
        }
        int carry = 0;
        while(!s.empty()){
            ListNode* tmp = s.top(); s.pop();
            tmp->val = (tmp->val << 1) + carry;
            carry = (tmp->val >= 10);
            tmp->val %= 10;
        }
        if(carry){
            ListNode* tmp = new ListNode(1);
            tmp->next = head;
            return tmp;
        }
        return head;
    }
};