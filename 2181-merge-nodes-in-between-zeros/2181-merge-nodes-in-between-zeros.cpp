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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* now = ans;
        head = head->next;
        while(head && head->next){
            if(head->val != 0){
                now->val += head->val;
            }
            else{
                now->next = new ListNode();
                now = now->next;
            }
            head = head->next;
        }
        return ans;
    }
};