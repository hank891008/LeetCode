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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            tmp = tmp->next;
            l++;
        }
        vector<ListNode*> ans(k);
        int add_one = l % k;
        int each = l / k;
        ListNode* now = head, *prev;
        for(int i = 0; i < min(l, k); i++){
            ans[i] = now;
            for(int j = 0; j < each; j++){
                prev = now;
                now = now->next;
            }
            if(i < add_one){
                prev = now;
                now = now->next;
            }
            prev->next = NULL;
            
        }
        return ans;
    }
};