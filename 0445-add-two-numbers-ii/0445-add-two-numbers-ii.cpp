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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       stack<int> s1, s2;
        ListNode* now = l1;
        while(now){
            s1.emplace(now->val);
            now = now->next;
        }
        now = l2;
        while(now){
            s2.emplace(now->val);
            now = now->next;
        }
        ListNode* ans = new ListNode();
        int carry = 0;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                ans->val += s1.top();    s1.pop();
            }
            if(!s2.empty()){
                ans->val += s2.top();    s2.pop();
            }
            carry = ans->val / 10;
            ans->val %= 10;
            ListNode* next = new ListNode(carry, ans);
            ans = next;
        }
        if(ans->val == 0){
            return ans->next;
        }
        return ans;
    }
};