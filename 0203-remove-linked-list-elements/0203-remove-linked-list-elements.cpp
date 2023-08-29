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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != NULL && head->val == val){
            head = head->next;
        }
        ListNode* now = head;
        while(now != NULL && now->next != NULL){
            while(now->next != NULL && now->next->val == val){
                now->next = now->next->next;
            }
            now = now->next;
        }
        return head;
    }
};