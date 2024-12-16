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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next == NULL){
            return head;
        }
        ListNode* now = head;
        unordered_map<int, int> m;
        unordered_set<int> need_remove;
        while(now){
            m[now->val]++;
            if(m[now->val] != 1){
                need_remove.insert(now->val);
            }
            now = now->next;
        }
        now = head;
        while(now && need_remove.count(now->val)){
            head = now->next;
            now = now->next;
        }
        if(head == NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast){
            while(fast && need_remove.count(fast->val)){
                fast = fast->next;
            }
            slow->next = fast;
            if(!fast){
                break;
            }
            slow = fast;
            fast = fast->next;
        }
            
        return head;
    }
};