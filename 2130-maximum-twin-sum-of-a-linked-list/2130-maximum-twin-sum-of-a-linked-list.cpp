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
    int ans = 0;
    ListNode* left;
    void dfs(ListNode* right) {
        if(right->next) {
            dfs(right->next);
        }
        ans = max(ans, left->val + right->val);
        left = left->next;
    }

    int pairSum(ListNode* head) {
        left = head;
        dfs(head);
        return ans;
    }
};