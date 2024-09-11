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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL){
            ListNode *gcd = new ListNode(__gcd(slow->val, fast->val));
            gcd->next = fast;
            slow->next = gcd;
            slow = fast;
            fast = fast->next;
        }
        return head;
    }
};